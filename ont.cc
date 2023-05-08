//
// ETSI de Telecomunicacion. Universidad de Malaga
// Titulacion: Grado en Ingenieria Telematica
// Asignatura: Redes de Acceso
// Profesora: Maria Carmen España Boquera
//
// Modelo de ONT
//

#include <string.h>
#include <omnetpp.h>
#include "trama_m.h"
#include "rafaga_m.h"

using namespace omnetpp;


/**
 * Clase que simula el comportamiento de la ONT
 */

class ont : public cSimpleModule
{

  protected:
   virtual void initialize();
   virtual void finish();
   virtual void handleMessage(cMessage *msg);

    //Proceso de registro-ranging
    virtual void procesarRANGING(trama *pk);
    virtual void enviarSERIAL_NUMBER();
    virtual void procesarASSIGN_ID(trama *pk);


  private:
    int numSerie; //Numero de serie propio (igual a´indice del vector de ONT)
    int PON_ID; //ID propio dentro de la PON, asigndo por la OLT
    double retardoEQ;//Retardo de ecualizacion que debe aplicar la ONT (calculado por la OLT y comunicado por ella)

    //Datos obtenidos desde omnetpp.ini
    int tipoTrafico;//Indica el tipo de trafico que genera la ONT
    double retardoProcesamiento;//Retardo de procesamiento de la ONT
    double RbinUp;//Regimen binario ascendente
    double tiempoActivacion; //Tiempo en que se enciende la ONT

    //Contrsol del estado de la ONT
    bool activada; //Indica si la ONT ha sido ya activado
    bool registrada; //Indica si la ONT ya esta registrada

};

Define_Module(ont);


////////////////////////////////////
// Funciones para el proceso de registro-ranging

////////////////////////////////////////////////////////////////
//FUNCIoN PARA EL PROCESADO DE UN MENSAJE RANGING

void ont::procesarRANGING(trama *pk){
    EV << "Llegada de un mensaje RANGING a la ONT con numero de serie " << numSerie << "\n";

    //La ONT responde tras un retardo de procesamiento

    //COMPLETAR respondiendo con el mensaje adecuado, utilizando la funcion adecuada
    sendDelayed(pk, retardoProcesamiento, "out");

    delete pk; //Despues de procesar la trama recibida, la elimina
}
//////////////////////////////////////////////////////
/// FUNCIoN PARA EL ENViO DE UN MENSAJE SERIAL_NUMBER

void ont::enviarSERIAL_NUMBER(){

    //Creacion de la rafaga
    rafaga *rfg = new rafaga("SERIAL_NUMBER", 0);

    //COMPLETAR la rafaga con los campos adecuados

    EV << "Envio de un mensaje SERIAL_NUMBER a la OTL desde la ONT con numero de serie "<< numSerie << "\n";

    rfg->setTipoMensaje(1);
    rfg->setNumSerie(numSerie);
    rfg->setTipoTrafico(tipoTrafico);

    //COMPLETAR enviadndo la rafaga tras el retardo de procesamiento
    sendDelayed(rfg, retardoProcesamiento, "out");
};
/////////////////////////////////////////////
//// FUNCIoN PARA PROCESAR EL MENSAJE ASSIGN_ID

void ont::procesarASSIGN_ID(trama *pk){
    EV << "Llegada de un mensaje ASSIGN_ID a la ONT con numero de serie " << numSerie << "\n";
    //Obtiene el PON_ID que se le ha asignado, leyendo el mensaje recibido
    PON_ID = pk->getAssignID();

    registrada = true; //La ONT ha quedado registrada
    EV << "La ONT con numero de serie " << numSerie <<  " se ha registrado con PON_ID " << PON_ID << "\n";

    //Obtener el retardo de ecualizacion leyendo el correspondiente campo del mensaje
    //COMPLETAR retardoEQ = ...
    retardoEQ = pk->getRetardoEQ();

    EV << "El retardo de ecualizacion calculado es de " << retardoEQ * 1e6 <<  " microsegundos \n";

    delete pk; //Despues de procesar la trama recibida, la eliminaa
};

///////////////////////////////////////
////////// INICIALIZACIoN /////////////

void ont::initialize()
{
        //Obtencion de parametros propios
        numSerie = par("numSerie");
        retardoProcesamiento = par("retardoProcesamiento");
        tiempoActivacion = par("tiempoActivacion");

        //Tipo de trafico
        tipoTrafico = par("tipoTrafico");

        //Regimen binario ascendente
        RbinUp = getParentModule()-> par("tasaBinariaUp"); //En Mbps
        RbinUp = RbinUp * 1000000;// En bps


        activada = false; //ONT inicialmente inactivada
        registrada = false; // ONT inicialmente no registrada

       // Crea el temporizador para activar la ONT
          cMessage *temporizadorActivacion = new cMessage("activacion");
        // Planifica la acivacion de la ONT
          scheduleAt(tiempoActivacion, temporizadorActivacion);

          EV << "ONT con numero de serie " << numSerie << " inicializada\n";

          if (tipoTrafico == 1){
              EV << "Trafico CBR \n";
          }
          else
          {
              if (tipoTrafico == 2){
                   EV << "Trafico ON-OFF \n";
              }
              else
              {
                  if (tipoTrafico == 4){
                         EV << "Trafico aleatorio \n";
                  }
                  else
                  {
                    EV << "Tipo no implementado \n";
                  }

              }
          };


}

///////////////////////////////////////////////////////////////////
//Funcion principal invocada cada vez que se recibe un mensaje

void ont::handleMessage(cMessage *msg)

{

 //AUTOMENSAJES

    if (msg->isSelfMessage()){
        const char* nombreAM;
        nombreAM = msg->getName();

        const char* ON = "activacion" ;
        if(*nombreAM == *ON){
                    activada = true;
                    delete msg; //Despues de procesar el automensaje, se elimina
                   EV << "Activada ONT: " << numSerie << "\n";
         }
     }//Fin de automensaje

    else{

// TRAMA RECIBIDA DESDE LA OLT
        if (activada){
          // Toma la trama recibida y examina si contiene un mensaje PLOAM
          // o si es trama sin PLOAM

           trama *pk = check_and_cast<trama *>(msg);

          //Examina el tipo de mensaje

            int tipo;
            tipo = pk->getTipoMensaje();

            if (tipo == 0){//Trama sin mensaje PLOAM
                //En el segundo ejercicio no deberia ocurrir
                EV << "Tipo de mensaje incorrecto en esta fase \n";
            }
            else{ //Trama con mensaje PLOAM
                if (tipo == 1) //El mensaje es RANGING
                {
                  // EV << "Mensaje RANGING en ONT: " << numSerie << "\n";;
                   if (registrada){ //Ya esta registradaa, asi que ignora el mensaje
                       delete pk;

                   } else{ //Como no esta registrada, acepta el mensaje y lo procesa
                            procesarRANGING(pk);
                   }
                }//Fin de RANGING
                else{//Otros tipos distintos de RANGING
                   if (tipo == 2){ //La trama es ASSIGN_ID
                       //Obtiene el numero de serie de la ONT destinataria
                       int numSerieRecibido= pk->getNumSerie();
                       if (numSerieRecibido == numSerie){ //Procesa la trama si es para ella
                           procesarASSIGN_ID(pk);
                       }
                       else{//Como no es para esta ONT, se ignora
                           delete pk;
                       }
                   }//fin de mensaje ASSIGN_ID
                   else{//Otros tipos distintos RANGING O ASSIGN_ID
                       delete pk; //Se ignora la trama
                       //No deberia ocurrir
                       EV << "Tipo de mensaje incorrecto \n";
                   }
              }//Fin de mensajes distintos de RANGING

            }//Fin de trama con menesajes PLOAM


    }//Fin de ONT activada
     else{//Si no esta activada, ignora el mensaje
            delete msg;
     }//Fin de no activada
}//fin de no es automensaje


}//Fin de hadlemessage


////////////////

void ont::finish(){


 }


