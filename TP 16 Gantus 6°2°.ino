#include<IRremote.h>;
#define ledRoja 13
#define trigg 11
#define echo 12

int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

//Motor A
int EntradaA1 = 2;
int EntradaA2 = 3;

//Motor B
int EntradaB1 = 4;
int EntradaB2 = 5;

//Motor C
int EntradaC1 = 6;
int EntradaC2 = 7;

//Motor D
int EntradaD1 = 8;
int EntradaD2 = 9;

void setup()

{  
   pinMode (11,OUTPUT);
  pinMode (12, INPUT);
    Serial.begin(9600);
//Motor A
pinMode(EntradaA1, OUTPUT);
pinMode(EntradaA2, OUTPUT);
//Motor B
pinMode(EntradaB1, OUTPUT);
pinMode(EntradaB2, OUTPUT);
//Motor C
pinMode(EntradaC1, OUTPUT);
pinMode(EntradaC2, OUTPUT);
//Motor D
pinMode(EntradaD1, OUTPUT);
pinMode(EntradaD2, OUTPUT);

irrecv.enableIRIn();

}

void loop()
{
 digitalWrite (trigg,LOW);
  delayMicroseconds (4);
  digitalWrite (trigg,HIGH);
  delayMicroseconds (10);
  digitalWrite (trigg,LOW);
  
 float duracion  = pulseIn(echo,HIGH);
 float distancia =  duracion * 0.017378;
   
 if(( distancia <= 200 )) { 
   digitalWrite(ledRoja, HIGH);
   delay(1000);
    Serial.println ("Objeto delante");
     Serial.print("Auto detenido");
   delay(500);
   Serial.print(".");
     delay(500);
     Serial.print(".");
      delay(500);
     Serial.println(".");
  //Motor A
digitalWrite(EntradaA1, LOW);
digitalWrite(EntradaA2, LOW);
//Motor B
digitalWrite(EntradaB1, LOW);
digitalWrite(EntradaB2, LOW);

//Motor C
digitalWrite(EntradaC1, LOW);
digitalWrite(EntradaC2, LOW);
//Motor D
digitalWrite(EntradaD1, LOW);
digitalWrite(EntradaD2, LOW);
 }else{
if (irrecv.decode(&results)) {
Serial.println(results.value, HEX);
irrecv.resume();
}

//Adelante
if (results.value ==0xFD8877)
{
 Serial.println("Avanzar");
//Motor A
digitalWrite(EntradaA1, HIGH);
digitalWrite(EntradaA2, LOW);
//Motor B
digitalWrite(EntradaB1, LOW);
digitalWrite(EntradaB2, HIGH);
//Motor C
digitalWrite(EntradaC1, HIGH);
digitalWrite(EntradaC2, LOW);
//Motor D
digitalWrite(EntradaD1, LOW);
digitalWrite(EntradaD2, HIGH);
delay(1000);
}

//Atras
if (results.value ==0xFD9867)
{
Serial.println("Retroceder");
//Motor A
digitalWrite(EntradaA1, LOW);
digitalWrite(EntradaA2, HIGH);
//Motor B
digitalWrite(EntradaB1, HIGH);

digitalWrite(EntradaB2, LOW);
//Motor C
digitalWrite(EntradaC1, LOW);
digitalWrite(EntradaC2, HIGH);
//Motor D
digitalWrite(EntradaD1, HIGH);
digitalWrite(EntradaD2, LOW);
delay(1000);
}

//Derecha
if (results.value ==0xFD6897)
{
Serial.println("Girar a la derecha");
//Motor A
digitalWrite(EntradaA1, HIGH);
digitalWrite(EntradaA2, LOW);
//Motor B
digitalWrite(EntradaB1, HIGH);
digitalWrite(EntradaB2, LOW);
//Motor C
digitalWrite(EntradaC1, LOW);
digitalWrite(EntradaC2, HIGH);
//Motor D
digitalWrite(EntradaD1, LOW);
digitalWrite(EntradaD2, HIGH);
delay(1000);

}

//Izquierda
if (results.value ==0xFD28D7)
{
Serial.println("Girar a la izquierda");
//Motor A
digitalWrite(EntradaA1, LOW);
digitalWrite(EntradaA2, HIGH);
//Motor B
digitalWrite(EntradaB1, LOW);
digitalWrite(EntradaB2, HIGH);
//Motor C
digitalWrite(EntradaC1, HIGH);
digitalWrite(EntradaC2, LOW);
//Motor D
digitalWrite(EntradaD1, HIGH);
digitalWrite(EntradaD2, LOW);
delay(1000);
}


//FRENO LENTO
if (results.value ==0xFDA857)
{
  Serial.println("Freno lento");
  //Motor A
digitalWrite(EntradaA1, LOW);
digitalWrite(EntradaA2, LOW);
//Motor B
digitalWrite(EntradaB1, LOW);
digitalWrite(EntradaB2, LOW);

//Motor C
digitalWrite(EntradaC1, LOW);
digitalWrite(EntradaC2, LOW);
//Motor D
digitalWrite(EntradaD1, LOW);
digitalWrite(EntradaD2, LOW);
}
  
if (results.value ==0xFD30CF)
{//Izquierda
Serial.println("FRENO INSTANTANEO");
//Motor A
digitalWrite(EntradaA1, 1);
digitalWrite(EntradaA2, HIGH);
//Motor B
digitalWrite(EntradaB1, 1);
digitalWrite(EntradaB2, HIGH);
//Motor C
digitalWrite(EntradaC1, HIGH);
digitalWrite(EntradaC2, 1);
//Motor D
digitalWrite(EntradaD1, HIGH);
digitalWrite(EntradaD2, 1);
delay(1000);
}
  if (results.value ==0xFD08F7)
{//Izquierda DOBLAR
Serial.println("Doblar a la Izquierda");
//Motor A
digitalWrite(EntradaA1, 1);
digitalWrite(EntradaA2, HIGH);
//Motor B
digitalWrite(EntradaB1, LOW);
digitalWrite(EntradaB2, HIGH);
//Motor C
digitalWrite(EntradaC1, HIGH);
digitalWrite(EntradaC2, LOW);
//Motor D
digitalWrite(EntradaD1, HIGH);
digitalWrite(EntradaD2, 1);
delay(1000);
}
    if (results.value ==0xFD48B7)
{//Izquierda DOBLAR
Serial.println("Doblar a la Derecha");
//Motor A
digitalWrite(EntradaA1, HIGH);
digitalWrite(EntradaA2, LOW);
//Motor B
digitalWrite(EntradaB1, 1);
digitalWrite(EntradaB2, HIGH);
//Motor C
digitalWrite(EntradaC1, HIGH);
digitalWrite(EntradaC2, 1);
//Motor D
digitalWrite(EntradaD1, LOW);
digitalWrite(EntradaD2, HIGH);
delay(1000);
}
}
}
