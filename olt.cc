//
// ETSI de Telecomunicacion. Universidad de Malaga
// Titulacion: Grado en Ingenieria Telematica
// Asignatura: Redes de Acceso
// Profesora: Maria Carmen España Boquera
//
// Modelo de OLT
//

#include <string.h>
#include <omnetpp.h>
#include "trama_m.h"
#include "rafaga_m.h"

using namespace omnetpp;


class olt : public cSimpleModule

{
private:

  double intervaloRANGING; //Intervalo de tiempo entre envio de mensajes RANGING
  double procesamientoOLT; //Retardo de procesamiento en la OLT
  double RbinDown;//Regimen binario descendente

  //Informacion sobre las tramas y rafagas
  double periodoTramas;//Periodo de envio de tramas
  int cabeceras; //Tamaño de las cabeceras de una rafaga
  int guarda;//Tamaño del tiempo de guarda entre rafagas


  //Variables con informacion sobre las ONT y el sentido ascendente
  double RbinUp;//Regimen binario ascendente
  int numONT; //Numero de ONT en la red
  double retardoProcesamientoMax;//Maximo retardo de procesamiento de una ONT
  double distanciaMax;//Distancia maxima de una ONT (en km)


  //Registro y ranging
  double tiempoEnvio;//Registra el envio de un mensaje RANGING
  int registrada[128]; // Marca si la ONT con el numero de serie dado por el indice ha sido registrada
  bool todasRegistradas;//Permite saber si ya se han registrado todas las ONT
  double retardoEQ; //Almacena el retardo de ecualizacion que debe aplicar una ONT
  double tablaRetardoEQ[128]; //Para la tabla final. Almacena los retardos de ecualizacion calculados
  int PON_ID[128]; //Almacena el PON_ID asignado a cada ONT segun su numero de serie
  int IDparaAsignar; //Se asignan correlativamente, desde 0
  bool tipoTrafico[128];//Almacena el tipo de trafico que genera la ONT, segun su PON_ID


  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();

    virtual void imprimirTabla();
    virtual void enviarRANGING();
    virtual void procesarSERIAL_NUMBER(rafaga *pk, int SNorigen);
    virtual void enviarASSIGN_ID(int SNdestino, int IDasignado, double retEQ);

};

Define_Module(olt);

//////////////////////////////////////////////////////////////

void olt::imprimirTabla(){


//Imprime por pantalla la tabla de retardos de ecualizacion


 EV << "----------------------------------------\n";
 EV << "TABLA DE RETARDOS DE ECUALIZACIoN CALCULADOS\n";
 EV << "----------------------------------------\n";
 for (int i=0; i<numONT; i++){
     EV << "ONT numero de serie: " << i << "\n";
     EV << "         PON_ID asignado: " << PON_ID[i]<< ".      Retardo de ecualizacion: " << tablaRetardoEQ[i]* 1e6 << " (microsegundos)\n";


 };
 EV << "----------------------------------------\n";
};

//////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
//FUNCIoN PARA EL ENViO DE UN MENSAJE RANGING

void olt::enviarRANGING(){

// Envia mensjes RANGING por difusion
// Se envian periodicamnete, con un periodo entre ellas para que no se solapen las respuestas
// Se envian tantos como numero de ONT, para que todas se registren


// Creacion de la trama base
    trama *tm = new trama("RANGING",0);

//Establecer el tipo de trama en el campo adecuado
    tm->setTipoMensaje(1);

//Las tramas se envian sin cuerpo


//Registrar el instante de tiempo en que se envia la trama
//Debe convertirse a double
    tiempoEnvio = (double) simTime().dbl();

 //COMPLETAR enviando la trama inmediatamente
    send(tm, "out");
};


////////////////////////////////////////////////////////////////
//FUNCIoN PARA EL PROCESADO DE UNA TRAMA DE SOLICITUD DE REGISTRO

void olt::procesarSERIAL_NUMBER(rafaga *pk, int SNorigen){

          EV <<"SERIAL_NUMBER recibido en OLT desde la ONT con numero de serie: "<< SNorigen << "\n";

          //Registrar del tiempo de llegada del comienzo de la rafaga
             simtime_t_cref tLlegada = pk->getArrivalTime()- pk->getDuration();
             double Llegada = tLlegada.dbl();
             EV << "Comenzo a llegar en el instante: " << Llegada * 1000 << "(milisegundos)\n";

             EV << "y el RANGING se envio en el instante: " << tiempoEnvio * 1000 << "(milisegundos)\n";

             // A partir de estos valores calcular el retardo de ecualizacion
             //COMPLETAR
             retardoEQ = Llegada - tiempoEnvio;

             //Asigna un PON_ID a la ONT e incrementa el valor para el siguiente
             PON_ID[SNorigen] = IDparaAsignar;
             IDparaAsignar =  IDparaAsignar + 1;
             EV << "El ID asignado a la ONT con numero de serie " << SNorigen << " es igual a: " << PON_ID[SNorigen] << "\n";

             EV << "El retardo de ecualizacion para la ONT con numero de serie " << SNorigen << " es igual a: " << retardoEQ * 1e6 << " (microsegundos)\n";
             tablaRetardoEQ[SNorigen] = retardoEQ; //Lo guarda en la tabla
             //Registra el tipo de trafico que generara la ONT
             //leyendo su valor del mensaje recibido
             //COMPLETAR
             tipoTrafico[PON_ID[SNorigen]] = pk->getTipoTrafico();

              EV << "El trafico que genera esta ONT es: " <<  tipoTrafico[PON_ID[SNorigen]] << "\n";


             //COMPLETAR enviando la respueta adecuada (usar la funcion creada para ello)
              send(pk, "out"); // REVISAR

         // Registrar la llegada de la respuesta: la ONT queda registrada

               registrada[SNorigen] = 1;

             //Comprueba si ya se han registrado todas las ONT


               int contadorNoRegistradas = numONT;

               for (int i=0; i<numONT; i++)
                {
                     contadorNoRegistradas = contadorNoRegistradas  - registrada[i];

                };

               EV << "Contador de registros pendientes = " << contadorNoRegistradas <<  "\n";


             if (contadorNoRegistradas == 0)
             {
                todasRegistradas= true;

                 EV << "Proceso de registro-ranging finalizado" <<  "\n";
                 imprimirTabla();
             }

             delete pk; //Despues de procesar la trama, la elimina
};
////////////////////////////////
// FUNCIoN PARA ENVIAR UN MENSAJE ASSIGN_ID
//
void olt::enviarASSIGN_ID(int SNdestino,int IDasignado, double retardoEQ){
    // Envia el mensaje ASSIGN_ID comunicando a la ONT el PON_ID asignado (IDasignado)
    //SNDestino es el numero de serie de la ONT destinataria

    // Creacion de la trama
    trama *tm = new trama("ASSIG_ID",0);

    //Establecer el tipo de trama en el campo adecuado
    tm->setTipoMensaje(2);
    //Indicar el ID asignado
     tm->setAssignID(IDasignado);
    //Indicar el retardo de ecualizacion calculado
     tm->setRetardoEQ(retardoEQ);
    //Indicar el numero de serie de la ONT destinataria
     tm->setNumSerie(SNdestino);

    EV << "La OLT envia ASSIGN_ID a la ONT con numero de serie " <<  SNdestino << " \n";

    //Enviar el mensaje inmediatamente
    //COMPLETAR
    send(tm,"out");
};

/////////////////// INICIALIZACIoN ////////////////////
/// y envio del primer mensaje RANGING ////////////////

void olt::initialize()
{
        //Obtiene los valores de los parametros globales desde el fichero de inicio
        RbinDown = getParentModule()-> par("tasaBinariaDown"); //En Mbps
        RbinDown = RbinDown * 1000000;//En bps
        RbinUp = getParentModule()-> par("tasaBinariaUp"); //En Mbps
        RbinUp = RbinUp * 1000000;// En bps
        numONT = getParentModule()->par("numONT");

        periodoTramas =  getParentModule()->par("periodoTramas");
        cabeceras = getParentModule()-> par("cabeceras");
        guarda = getParentModule()-> par("guarda");

        retardoProcesamientoMax = getParentModule()->par("retardoProcesamientoMax"); //Valor maximo de retardo de procesamiento en la ONT
        distanciaMax = getParentModule()->par("distanciaMax"); //Mazima distancia a la que puede encontrarse una ONT

    //Para el proceso de registro-ranging
    intervaloRANGING = par("intervaloRANGING");
    todasRegistradas = false;
    IDparaAsignar = 0;

    //Inicialmente no hay ninguna ONT registrada
      for (int i=0; i<numONT; i++)
      {
          registrada[i] = 0; //Todavia no esta registrada

      };

         enviarRANGING();
      // Crea el temporizador para enviar el siguiente RANGING
         cMessage *temporizadorRANGING = new cMessage("RANGING");
      // Planifica el envio del siguiente RANGING
         scheduleAt(intervaloRANGING, temporizadorRANGING);


    EV << "OLT inicializada\n";

}
///////////////////////////////////////////////
void olt::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()){
        const char* nombreAM;
        nombreAM = msg->getName();
        const char* RNG = "RANGING" ;

        //Automensaje para enviar RANGING
        //Si quedan ONT pendientes de registro, se envia otro RANGING
        if ((*nombreAM == *RNG)and (!todasRegistradas)){
                      enviarRANGING();
                     // Crea el temporizador para enviar el proximo RANGING
                      cMessage *temporizadorRANGING = new cMessage("RANGING");
                     // Planifica el envio del siguiente RANGING
                      scheduleAt(simTime().dbl()+ intervaloRANGING, temporizadorRANGING);

         }
        delete msg;// Despues de procesar el automensaje, se borra
    }//Fin de procesado de automensajes


    else { //No es un automensaje
       // Toma la rafaga recibida y obtiene el numero de serie de la ONT origen

        rafaga *pk = check_and_cast<rafaga *>(msg);
        int SNorigen;
        SNorigen = pk->getNumSerie();

        // Luego examina el tipo de mensaje
        int tipo;
        tipo = pk->getTipoMensaje();



////////////////////////////////////////////////////////////////////////////////////
        if (tipo == 1) //Mensaje SERIAL_NUMBER
       {
           procesarSERIAL_NUMBER(pk, SNorigen);

       }//Fin de procesado SERIAL_NUMBER
        else{
            EV << "Tipo de mensaje incorrecto \n";
        };

//////////////////////////////////////////////////////////////////////////////////////////////////////////


  }; //Fin de "No es un automensaje"

}//Fin de handleMessage




void olt::finish(){

}





