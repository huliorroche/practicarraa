//
// ETSI de Telecomunicación. Universidad de Málaga
// Titulación: Grado en Ingeniería Telemática
// Asignatura: Redes de Acceso
// Profesora: María Carmen España Boquera
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

