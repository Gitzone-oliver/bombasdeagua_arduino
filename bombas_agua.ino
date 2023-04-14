
/*
AUTOR: Oliver Gamaliel Campos Trujillo
PROGRAMA: Encedido de dos motores en alternancia para el llenado de
          una cisterna
FECHA: 02/02/2020
REV:A.0
*/
// Nombramiento de pines
int cisterna_bajo = 2;
int cisterna_alto= 3;
int presion = 4;
int manual_auto =7;
int B1_B2_switch = 9;
int ON_OFF = 8;
//actuadores y salidas
int MOTOR1= 12; 
int MOTOR2= 13;
// Variables de conteo
//int ESCALA_MIN = 20*1000; //60seg x 1000 miliseg
//unsigned long TIEMPO_ALTENAR = .001*ESCALA_MIN;  // Es en minutos (.2 min == 20seg)
//unsigned long TIEMPO_RESET = TIEMPO_ALTENAR*2  // Se resetea el contador del tiempo
unsigned long previousMillis = 0;
unsigned long currentMillis =0;

void setup() {
pinMode(cisterna_bajo,INPUT);//Sensor activacion bajo nivel
pinMode(cisterna_alto,INPUT);//Sensor activacion alto nivel
pinMode(presion, INPUT); //Sensor de presion
pinMode(manual_auto, INPUT); //Manual/Auto
pinMode(ON_OFF,      INPUT); //Encendido/Apagado 
pinMode(B1_B2_switch,INPUT); //Eleccion MOTOR1 / MOTOR2

pinMode(MOTOR1,OUTPUT); //Motor B1
pinMode(MOTOR2,OUTPUT); //Motor B2
}

void loop() {
// Get snapshot of time
unsigned long currentMillis = millis();
   
if (digitalRead(ON_OFF) == true)
 {
  if (digitalRead(manual_auto) == true) 
  {
    if (digitalRead(B1_B2_switch) == true)
     {
      if (digitalRead(presion) == true & digitalRead(cisterna_alto) == false) 
       {
        digitalWrite(MOTOR2, LOW); //BOMBA 2 SE APAGA
        delay(1000);//1000 miliseg = 1 seg de retraso
        digitalWrite(MOTOR1, HIGH); //BOMBA 1 ENCENDIDA 
       }
      else
       {
        digitalWrite(MOTOR1, LOW); //BOMBA 1 SE APAGA
        digitalWrite(MOTOR2, LOW); //BOMBA 2 SE APAGA 
       } //else --> sensores presion y llenado   
     } //if B1
    else
     {
       if (digitalRead(presion) == true & digitalRead(cisterna_alto) == false) 
        {
         digitalWrite(MOTOR1, LOW); //BOMBA 1 APAGADA
         delay(1000); //1000 miliseg=1 segu
         digitalWrite(MOTOR2, HIGH); //BOMBA 2 ENCENDIDA 
        }//if --> Presion y llenado
       else
        {
         digitalWrite(MOTOR1, LOW); //BOMBA 1 SE APAGA
         digitalWrite(MOTOR2, LOW); //BOMBA 2 SE APAGA 
        }//else --> Presion y llenado  
      }//else -->  B2
  }//Elige entre motor 1 o 2
  
  else // AUTO
  {
    
   if ((currentMillis - previousMillis) > 2000)  
    {
      if ((currentMillis - previousMillis) > 4000)  
        { //Use the snapshot to set track time until next event
         previousMillis = currentMillis;
        }
     
        if (digitalRead(presion) == true & digitalRead(cisterna_alto) == false) 
        {
         digitalWrite(MOTOR2, LOW); //BOMBA 2 SE APAGA
         delay(1000);//1000 miliseg = 1 seg de retraso
         digitalWrite(MOTOR1, HIGH); //BOMBA 1 ENCENDIDA
        }
        else
        {
         digitalWrite(MOTOR1, LOW); //BOMBA 1 SE APAGA
         digitalWrite(MOTOR2, LOW); //BOMBA 2 SE APAGA 
        }   
     } 
    else // Sobre pasa el tiempo umbral
     {
        if (digitalRead(presion) == true & digitalRead(cisterna_alto) == false) 
        {
         digitalWrite(MOTOR1, LOW); //BOMBA 1 APAGADA
         delay(1000);//1000 miliseg=1 segu
         digitalWrite(MOTOR2, HIGH); //BOMBA 2 ENCENDIDA
         delay(1000);//1000 miliseg=1 segu
        }//if --> Presion y llenado
        else
        {
         digitalWrite(MOTOR1, LOW); //BOMBA 1 SE APAGA
         digitalWrite(MOTOR2, LOW); //BOMBA 2 SE APAGA 
        }//else --> Presion y llenado   
     }//else --> Segundo ciclo auto
    
  }//manual-auto
 }//ON 
 
 else // SE APAGAN LOS MOTORES DE LAS BOMBAS
 {//Se apagan los dos motores sin importar entrada de sensores
  digitalWrite(MOTOR1, LOW); //BOMBA 1 APAGADA
  digitalWrite(MOTOR2, LOW); //BOMBA 2 APAGADA
 }//Fin condicion else

}// Fin de loop
