//
// ETSI de Telecomunicaci�n. Universidad de M�laga
// Titulaci�n: Grado en Ingenier�a Telem�tica
// Asignatura: Redes de Acceso
// Profesora: Mar�a Carmen Espa�a Boquera
//
// R�gaga generada por una ONT hacia la OLT
//

packet rafaga
{
    int tipoMensaje = 0; 
    // Los mensajes PLOAM pueden ser de los siguientes tipos:
    // SIN MENSAJE(0)
    // SERIAL NUMBER(1)
    int numSerie;
   //N�mero de serie de la ONT origen del mensaje
    int IdONT; //Identificador de la ONT
    int BWReport;//Informe sobre el estado de la cola
    int tipoTrafico; //La ONT informa a la OLT del tipo de tr�fico que generar� 
					//Se incluye en mensajes SERIAL NUMBER
   

    
}

