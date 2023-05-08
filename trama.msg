//
// ETSI de Telecomunicación. Universidad de Málaga
// Titulación: Grado en Ingeniería Telemático
// Asignatura: Redes de Acceso
// Profesora: María Carmen España Boquera
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
   //Número de serie de la ONT destinaaria del mensaje
      
    int assignID;
    //Valor de identificador asignado en mensajes ASSIGN_ID
   
   	double retardoEQ;
   	//Cuando el mensaje es de tipo ASSIGN_ID, contiene el retardo de ecualización
   	//calculado por la OLT
   	
   	//Los siguientes campos conforman el mapa de la trama ascendente
   	int tamanoMapa;
   	int AllocID[128];//Identificador de la ONT a la cual se asigna el intervalo
    int inicio[128];//Inicio del intervalo
    int fin[128];//Fin del intervalo
 

}

