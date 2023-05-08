//
// ETSI de Telecomunicación. Universidad de Málaga
// Titulación: Grado en Ingeniería Telemática
// Asignatura: Redes de Acceso
// Profesora: María Carmen España Boquera
//
// Modelo de OLT
//

#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

/**
 * Clase que simula el comportamiento de la OTL
 */

class olt : public cSimpleModule
{
private:

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);


};

Define_Module(olt);



void olt::initialize()
{


}

void olt::handleMessage(cMessage *msg)
{

    }












