//
// ETSI de Telecomunicaci�n. Universidad de M�laga
// Titulaci�n: Grado en Ingenier�a Telem�tica
// Asignatura: Redes de Acceso
// Profesora: Mar�a Carmen Espa�a Boquera
//
// Modelo de splitter
//

#include <string.h>
#include <omnetpp.h>
//#include "trama_m.h"
//#include "rafaga_m.h"

using namespace omnetpp;

/**
 * Clase que simula el comportamiento del splitter
 */

class splitter : public cSimpleModule
{
private:
    int numPuertos; //N�mero de puertos

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void difundeMessage(cMessage *msg);



};

Define_Module(splitter);

void splitter::difundeMessage(cMessage *msg){
// difusi�n del mensaje a todas las ONT
// simula el comportamiento del enlace desdendente desde el splitter las ONT
    for (int i=0; i<numPuertos; i++){
        cMessage *copia = msg->dup();
        send(copia, "outONT", i);
        //EV << "Splitter env�a trama a ONT " << i <<" \n";
    };
    delete msg;
}

void splitter::initialize()
{
 numPuertos = par("numPuertos");
 gate("inOLT")->setDeliverOnReceptionStart(true);
 for (int i=0; i<numPuertos; i++){
  gate("inONT",i)->setDeliverOnReceptionStart(true);
 };
}

void splitter::handleMessage(cMessage *msg)
{

  int inOLTId = gate("inOLT")->getId();//Identificador de la puerta de entrada desde la OLT

 //Cada vez que se recibe un mensaje procedente de la OLT, debe difundirlo a todas las ONT
  if (msg -> arrivedOn(inOLTId)){
           difundeMessage(msg);
  }

  else

 //Si el mensaje procede de una ONT, se transfiere a la salida hacia la OLT
  {
      send(msg, "outOLT");


  }
 }












