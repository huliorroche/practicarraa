//
// ETSI de Telecomunicación. Universidad de Málaga
// Titulación: Grado en Ingeniería Telemática
// Asignatura: Redes de Aceso
// Profesora: María Carmen España Boquera
// 
// Simulación simplificada de una red GPON
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
        int numONT; //Número de ONT
        double tasaBinariaDown @unit(Mbps);
        double tasaBinariaUp @unit(Mbps);
        double periodoTramas;
        double retardoProcesamientoMax;
        double distanciaMax;


        //Tamaños relativos a ráfagas ascendentes
        int guarda;
        int cabeceras;
        
        //Ramaños relativos a los datos generados en las ONT
        int tamanoMaxDatos;
        int tamanoMinDatos;
        int paqueteCBR;
        double tiempoON;
        double tiempoOFF;

		//Datos relativos a la gestión del ancho de banda
        int maxTamCola;
        int maxAsignacion;
        int asignacionFija;
        int estrategiaAsignacion;


    types:

		//Canales descendentes de conexión entre el splitter y las ONT
		//o entre dos spliters
		channel C1_down extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaDown;
            double longitud @unit(km);
            longitud = 1km;
            delay = this.longitud / 200000km * 1s;

        }
        
        channel C2_down extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaDown;
            double longitud @unit(km);
            longitud = 2km;
            delay = this.longitud / 200000km * 1s;

        }
        
         channel C3_down extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaDown;
            double longitud @unit(km);
            longitud = 3km;
            delay = this.longitud / 200000km * 1s;

        }
        
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



		//Canales ascendentes de conexión entre splitter y las ONT 
		//o entre dos splitters    

		channel C1_up extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaUp;
            double longitud @unit(km);
            longitud = 1km;
            delay = this.longitud / 200000km * 1s;
        }
        
		channel C2_up extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaUp;
            double longitud @unit(km);
            longitud = 2km;
            delay = this.longitud / 200000km * 1s;
        }
        
		channel C3_up extends ned.DatarateChannel
        {
            datarate = parent.tasaBinariaUp;
            double longitud @unit(km);
            longitud = 3km;
            delay = this.longitud / 200000km * 1s;
        }
        
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

	//La OLT es única
        olt1: olt;
        
    //Un splitter particular de tipo 1 x 2
    
        splitter1: splitter {
        	numPuertos = 2;
            gates:
                outONT[2];
                inONT[2];
        }
        
        splitter2: splitter {
        	numPuertos = 2;
            gates:
                outONT[2];
                inONT[2];
        }
                
        splitter3: splitter {
        	numPuertos = 8;
            gates:
                outONT[8];
                inONT[8];
        }

    connections:
    
	///////////////////////
	//SENTIDO DESCENDENTE
	///////////////////
	// ONU 0
	olt1.out --> C3_down --> splitter3.inOLT;
	splitter3.outONT[0] --> C10_down --> splitter1.inOLT;
	splitter1.outONT[0] --> C2_down --> onts[0].in;
	
	// ONU 1
	splitter1.outONT[1] --> C2_down --> onts[1].in;
	
	// ONU 2
	splitter3.outONT[1] --> C10_down --> splitter2.inOLT;
	splitter2.outONT[0] --> C1_down --> onts[2].in;
	
	// ONU 3
	splitter2.outONT[1] --> C1_down --> onts[3].in;

	// ONU 4
    splitter3.outONT[2] --> C2_down --> onts[4].in;
    
    // ONU 5
    splitter3.outONT[3] --> C2_down --> onts[5].in;
    
    // ONU 6
    splitter3.outONT[4] --> C2_down --> onts[6].in;
    
    // ONU 7
    splitter3.outONT[5] --> C2_down --> onts[7].in;
    
    // ONU 8
    splitter3.outONT[6] --> C2_down --> onts[8].in;
    
    // ONU 9
    splitter3.outONT[7] --> C2_down --> onts[9].in;
  
	///////////////////////
	//SENTIDO ASCENDENTE //
	///////////////////////
	
	// ONU 0
	olt1.in <-- C3_up <-- splitter3.outOLT;
	splitter3.inONT[0] <-- C10_up <-- splitter1.outOLT;
	splitter1.inONT[0] <-- C2_up <-- onts[0].out;
	
	// ONU 1
	splitter1.inONT[1] <-- C2_up <-- onts[1].out;
	
	// ONU 2
	splitter3.inONT[1] <-- C10_up <-- splitter2.outOLT;
	splitter2.inONT[0] <-- C1_up <-- onts[2].out;
	
	// ONU 3
	splitter2.inONT[1] <-- C1_up <-- onts[3].out;

	// ONU 4
    splitter3.inONT[2] <-- C2_up <-- onts[4].out;
    
    // ONU 5
    splitter3.inONT[3] <-- C2_up <-- onts[5].out;
    
    // ONU 6
    splitter3.inONT[4] <-- C2_up <-- onts[6].out;
    
    // ONU 7
    splitter3.inONT[5] <-- C2_up <-- onts[7].out;
    
    // ONU 8
    splitter3.inONT[6] <-- C2_up <-- onts[8].out;
    
    // ONU 9
    splitter3.inONT[7] <-- C2_up <-- onts[9].out;
 }




