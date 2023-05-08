//
// ETSI de Telecomunicaci�n. Universidad de M�laga
// Titulaci�n: Grado en Ingenier�a Telem�tica
// Asignatura: Redes de Acceso
// Profesora: Mar�a Carmen Espa�a Boquera
//
// Modelo de ONT
//

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

/**
 * Clase que simula el comportamiento de la ONU
 */

class ont : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(ont);



void ont::initialize()

{

}

void ont::handleMessage(cMessage *msg)

{

}

