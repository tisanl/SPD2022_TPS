// C++ code
//

#include <LiquidCrystal.h>
#include<Servo.h>

LiquidCrystal lcd(2,3,4,5,6,7);

Servo motorSegundos;
Servo motorMinutos;
Servo motorHoras;

unsigned long millisAntes = 0;

int segundos = 0;
int minutos = 0;
int horas = 0;

int botonHoras;
int botonAntesHoras = 0;
int botonMinutos;
int botonAntesMinutos = 0;
int botonSegundos;
int botonAntesSegundos = 0;
 
void setup()
{
  lcd.begin(16, 2);
  
  motorSegundos.attach(11);
  motorMinutos.attach(10);
  motorHoras.attach(9);
  
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop()
{
  unsigned long millisAhora = millis();
  unsigned long banderaMillis = millisAhora - millisAntes;
  
  if(horas == 0 && minutos == 0 && segundos == 0)
  {
    lcd.setCursor(4,0);
    lcd.print("Horario");
    lcd.setCursor(4,1);
    lcd.print("00:00:00");
  }
  
  //INCREMENTO
  if(banderaMillis >= 1000)
  {
    segundos ++;
    //TIMING CON MILLIS
  	millisAntes = millisAhora;
  }
  if(segundos == 60)
  {
     segundos = 0;
     minutos ++;    
  }
  if(minutos == 60)
  {
    minutos = 0;
    horas ++;
  }
  if(horas == 24)
  {
    horas = 0;
  }
  
  //IMPRIMIR HORAS
  lcd.setCursor(4,1);
  if(horas < 10)
  {
    lcd.print("0");
  }
  lcd.print(horas);
  //IMPRIMIR MINUTOS
  lcd.setCursor(7,1);
  if(minutos < 10)
  {
    lcd.print("0");
  }
  lcd.print(minutos);
  //IMPRIMIR SEGUNDOS
  lcd.setCursor(10,1);
  if(segundos < 10)
  {
    lcd.print("0");
  }
  lcd.print(segundos);
  
  //MAPEO DE SERVOS
  motorSegundos.write(map(segundos, 0, 59, 0, 180));
  motorMinutos.write(map(minutos, 0, 59, 0, 180));
  motorHoras.write(map(horas, 0, 23, 0, 180));
  
  //BOTONES
  //BOTON SEGUNDOS
  botonSegundos = digitalRead(13);
  if(botonSegundos == 1 && botonAntesSegundos == 0)
  {
    segundos ++;
  }  
  botonAntesSegundos = botonSegundos;
  //BOTON MINUTOS
  botonMinutos = digitalRead(12);
  if(botonMinutos == 1 && botonAntesMinutos == 0)
  {
    minutos ++;
  }  
  botonAntesMinutos = botonMinutos;
  //BOTON HORAS
  botonHoras = digitalRead(8);
  if(botonHoras == 1 && botonAntesHoras == 0)
  {
    horas ++;
  }  
  botonAntesHoras = botonHoras;
  
  delay(20);
}