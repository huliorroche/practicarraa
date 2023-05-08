//
// ETSI de Telecomunicaci�n. Universidad de M�laga
// Titulaci�n: Grado en Ingenier�a Telem�tica
// Asignatura: Redes de Aceso
// Profesora: Mar�a Carmen Espa�a Boquera
// 
// Simulaci�n simplificada de una red GPON
//
simple ont
{
    parameters:
        int numSerie;
		int tipoTrafico;
        double retardoProcesamiento;
        double tiempoMedioEntreDatos;
        double tiempoActivacion;

    gates:
        input in;
        output out;

}

simple olt
{
    parameters:
        double intervaloRANGING;
        double procesamientoOLT;

    gates:
        output out;
        input in;
}

simple splitter
{
    parameters:
		int numPuertos;
    gates:
        output outONT[];
        input inONT[];
        output outOLT;
        input inOLT;
}


network gpon
{
    parameters:
        int numONT; //N�mero de ONT
        double tasaBinariaDown @unit(Mbps);
        double tasaBinariaUp @unit(Mbps);
        double periodoTramas;
        double retardoProcesamientoMax;
        double distanciaMax;


        //Tama�os relativos a r�fagas ascendentes
        int guarda;
        int cabeceras;
        
        //Rama�os relativos a los datos generados en las ONT
        int tamanoMaxDatos;
        int tamanoMinDatos;
        int paqueteCBR;
        double tiempoON;
        double tiempoOFF;

		//Datos relativos a la gesti�n del ancho de banda
        int maxTamCola;
        int maxAsignacion;
        int asignacionFija;
        int estrategiaAsignacion;


    types:

//Canales descendentes de conexi�n entre el splitter y las ONT
//o entre dos spliters

        channel C5_down extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaDown;
            double longitud @unit(km);
            longitud = 5km;
            delay = this.longitud / 200000km * 1s;

        }

        channel C10_down extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaDown;
            double longitud @unit(km);
            longitud = 10km;
            delay = this.longitud / 200000km * 1s;

        }

        channel C15_down extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaDown;
            double longitud @unit(km);
            longitud = 15km;
            delay = this.longitud / 200000km * 1s;
        }



//Canales ascendentes de conexi�n entre splitter y las ONT 
//o entre dos splitters    

        channel C5_up extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaUp;
            double longitud @unit(km);
            longitud = 5km;
            delay = this.longitud / 200000km * 1s;
        }
        channel C10_up extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaUp;
            double longitud @unit(km);
            longitud = 10km;
            delay = this.longitud / 200000km * 1s;
        }
        channel C15_up extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaUp;
            double longitud @unit(km);
            longitud = 15km;
            delay = this.longitud / 200000km * 1s;
        }


    submodules:


        onts[numONT]: ont {
            parameters:
                numSerie = index;

        }

	//La OLT es �nica
        olt1: olt;
        
    //Un splitter particular de tipo 1 x 2
    
        splitter1: splitter {
        	numPuertos = 2;
            gates:
                outONT[2];
                inONT[2];
        }

//COMPLETAR definiendo todos los splitters de la red


    connections:

///////////////////////
//SENTIDO DESCENDENTE//
///////////////////////

//COMPLETAR realizando todas las conexiones necesarias en este sentido
    
///////////////////////
//SENTIDO ASCENDENTE //
///////////////////////

//COMPLETAR realizando todas las conexiones necesarias en este sentido
 }



