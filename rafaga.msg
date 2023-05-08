//
// ETSI de Telecomunicación. Universidad de Málaga
// Titulación: Grado en Ingeniería Telemática
// Asignatura: Redes de Acceso
// Profesora: María Carmen España Boquera
//
// Rágaga generada por una ONT hacia la OLT
//

packet rafaga
{
    int tipoMensaje = 0; 
    // Los mensajes PLOAM pueden ser de los siguientes tipos:
    // SIN MENSAJE(0)
    // SERIAL NUMBER(1)
    int numSerie;
   //Número de serie de la ONT origen del mensaje
    int IdONT; //Identificador de la ONT
    int BWReport;//Informe sobre el estado de la cola
    int tipoTrafico; //La ONT informa a la OLT del tipo de tráfico que generará 
					//Se incluye en mensajes SERIAL NUMBER
   

    
}

