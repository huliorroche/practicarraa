//
// ETSI de Telecomunicaci�n. Universidad de M�laga
// Titulaci�n: Grado en Ingenier�a Telem�tico
// Asignatura: Redes de Acceso
// Profesora: Mar�a Carmen Espa�a Boquera
//
// Modelo trama descendente
//
//
//Trama enviada desde la OLT hacia las ONT
//
packet trama
{

    int tipoMensaje = 0; 
    // Los mensajes PLOAM pueden ser de los siguientes tipos:
    // SIN MENSAJE(0)
    // RANGING(1)
    // ASSIGN_ID (2)
   
    int numSerie;
   //N�mero de serie de la ONT destinaaria del mensaje
      
    int assignID;
    //Valor de identificador asignado en mensajes ASSIGN_ID
   
   	double retardoEQ;
   	//Cuando el mensaje es de tipo ASSIGN_ID, contiene el retardo de ecualizaci�n
   	//calculado por la OLT
   	
   	//Los siguientes campos conforman el mapa de la trama ascendente
   	int tamanoMapa;
   	int AllocID[128];//Identificador de la ONT a la cual se asigna el intervalo
    int inicio[128];//Inicio del intervalo
    int fin[128];//Fin del intervalo
 

}

