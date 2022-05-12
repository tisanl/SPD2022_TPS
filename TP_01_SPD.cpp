/*
 *	Trabajo Práctico 1: Cronómetro Binario
 *
 *	Al iniciar la simulacion, todos los led deben comenzar apagados.
 *	Cada 1 segundo que transcurra, se deben encender los led
 *	de acuerdo al numero que representan.
 *
 *	Ejemplo:
 *   
 *	El numero 15 (0000001111) se representaria encendiendo los 
 *	leds AMARILLO y NARANJA.
 *	Al pasar al numero 16 (0000010000), se deben apagar todos 
 *	los led anteriores y encenderse uno de los leds VERDES. 
 *	Notese, en el ejemplo los 0 representan los led apagados 
 *	y los 1 los led encendidos). 
 *   
 *	-------------------------------------------------------
 *   
 *	Al presionarse el boton START, debe iniciar el cronometro.
 *	Volver a presionarlo hace que la secuencia se detenga. 
 *  (Como si se hubiese presionado pausa).
 *	Al presionarse el boton RESET, el cronometro
 *	debe reiniciarse y arrancar de 0.
 *
 *	Tip: Modularizar la función que controla el encendido de los 
 *	LEDS y de ser posible, todo el código para evitar repetir lineas lo mas posible.
 *  Usar millis para controlar el tiempo del contador para que el cambio de los 
 *	leds encendidos sea perceptible para el ojo humano y 
 *	documentar cada función creada en el código. 
 *	Un breve comentario que diga que es lo que hace esa función
 *  y de corresponder, que retorna).

//##### Una Ayudita #####
//--- Defines ---//
#define ZERO_TO_HERO 0          //? To start the counter from 0
#define BUTTON_START 2
#define BUTTON_RESET 3
#define FIRST_LED 4             //? First pin of the leds
#define LAST_LED 13             //? Last pin of the leds
#define BASE_MILLI_SECONDS 1000 //? Secods expresed in miliseconds
#define MAX_SECONDS 1023        //! Max amount of secods to show
//--- End Defines ---//
*/

// SETUP
void setup()
{
  	pinMode(4, OUTPUT);
 	pinMode(5, OUTPUT);
 	pinMode(6, OUTPUT);
 	pinMode(7, OUTPUT);
 	pinMode(8, OUTPUT);
 	pinMode(9, OUTPUT);
  	pinMode(10, OUTPUT);
 	pinMode(11, OUTPUT);
 	pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
  
  	pinMode(2, INPUT);
    pinMode(3, INPUT);
  
  	Serial.begin(9600); 	
}

//DECLARACION DE VARIABLES
unsigned long millisAntes = 0;

int estadoLed4 = LOW;
int estadoLed5 = LOW;
int estadoLed6 = LOW;
int estadoLed7 = LOW;
int estadoLed8 = LOW;
int estadoLed9 = LOW;
int estadoLed10 = LOW;
int estadoLed11 = LOW;
int estadoLed12 = LOW;
int estadoLed13 = LOW;

int botonStart;
int botonAntesStart = 0;

int botonReset;
int botonAntesReset = 0;

int flag = 1;

int segundo = 0;

//FUNCION PARA CAMBIAR ESTADO Y MOSTRAR
void cambiarYMostrarEstado(int pin, int* estado)
{
  	*estado = !(*estado);
  	digitalWrite(pin, *estado);
}

//FUNCION MOSTRAR EN EL MONITOR
void imprimirEnMonitor(int segundo)
{
  	Serial.print("Segundo numero: ");
    Serial.print(segundo);
   	Serial.print(" || En binario: ");
     
  	/*Serial.print(digitalRead(13));
    Serial.print(digitalRead(12));
    Serial.print(digitalRead(11));
    Serial.print(digitalRead(10));
    Serial.print(digitalRead(9));
    Serial.print(digitalRead(8));
    Serial.print(digitalRead(7));
    Serial.print(digitalRead(6));
    Serial.print(digitalRead(5));
    Serial.print(digitalRead(4));*/ //o esta
    Serial.print(segundo, BIN); //o esta, copado chiche este
    Serial.print("\n");
}

//FUNCION RESET
void resetCronometro()
{
    digitalWrite(4, estadoLed4 = LOW);
    digitalWrite(5, estadoLed5 = LOW);
    digitalWrite(6, estadoLed6 = LOW);
    digitalWrite(7, estadoLed7 = LOW);
    digitalWrite(8, estadoLed8 = LOW);
    digitalWrite(9, estadoLed9 = LOW);
    digitalWrite(10, estadoLed10 = LOW);
    digitalWrite(11, estadoLed11 = LOW);
    digitalWrite(12, estadoLed12 = LOW);
    digitalWrite(13, estadoLed13 = LOW);
}

//FUNCION LOOP
void loop()
{   	
  	unsigned long millisAhora = millis();
  	unsigned long banderaMillis = millisAhora - millisAntes;
  	
  	if(segundo == 0 || segundo == 1024)
    {
      segundo = 0;
      resetCronometro();
    }
  
  	//BOTON START/PAUSA
   	botonStart = digitalRead(2);
  	if(botonStart == 1 && botonAntesStart == 0)
    {
      flag = !flag;
    }  
  	botonAntesStart = botonStart;
    
  	//BOTON RESET CRONOMETRO
  	botonReset = digitalRead(3);
    if(botonReset == 1 && botonAntesReset == 0)
    {
      Serial.print("\nSe a reiniciado el reloj\n\n");
      segundo = 0;
    }
  	botonAntesReset = botonReset;
  
  	//PRENDER O APAGAR LEDS
    if(banderaMillis >= 1000 && flag == 0)
    {
      cambiarYMostrarEstado(4, &estadoLed4);
      
      if(estadoLed4 == 0)
      {
        cambiarYMostrarEstado(5, &estadoLed5);

        if(estadoLed5 == 0)
        {
          cambiarYMostrarEstado(6, &estadoLed6);

          if(estadoLed6 == 0)
          {
            cambiarYMostrarEstado(7, &estadoLed7);
                
            if(estadoLed7 == 0)
            {
           	  cambiarYMostrarEstado(8, &estadoLed8);

              if(estadoLed8 == 0)
              {
                cambiarYMostrarEstado(9, &estadoLed9);

                if(estadoLed9 == 0)
                {
                  cambiarYMostrarEstado(10, &estadoLed10);

                  if(estadoLed10 == 0)
                  {
                    cambiarYMostrarEstado(11, &estadoLed11);
                                  	
                    if(estadoLed11 == 0)
                    {
                      cambiarYMostrarEstado(12, &estadoLed12);
                                      	                                      
                      if(estadoLed12 == 0)
                      {
                        cambiarYMostrarEstado(13, &estadoLed13);
                      }
                    }
                  }
                }
              }
            }
          }
        }
	  }

      //TIMING CON MILLIS
      millisAntes = millisAhora;

      //MOSTRAR EN MONITOR
      segundo ++;
      imprimirEnMonitor(segundo);      	
    }
    
  	delay(20); //para el correcto funcionamiento del simulador que le cuesta aveces
}