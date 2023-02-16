int Sensor = 0 ;
int var = 0;
void setup()

{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  
  pinMode (3, OUTPUT);
}

void loop()
{	
  int lectura = analogRead(Sensor);  
  float voltage =  5.0 /1024 * lectura; 
  int temp = voltage * 100 -50;

  if (temp > 25){
	analogWrite(6,255);
    Serial.print ("Temperatura ALTA: ");
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    Serial.println (temp);
      digitalWrite(3,LOW);  
  
	  	digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
      delay(2000);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
      delay(2000);
   	digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
      delay(2000);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
      delay(2000);

    var = var * 0;
  }
    if (temp < -49){
       digitalWrite(13, LOW);
   	   digitalWrite(12, HIGH);
       while(var <3){
        Serial.println ("SISTEMA 3 MINUTOS ACTIVADO");
        Serial.print ("While (Minutos): ");
        Serial.println(var);
        analogWrite(6,255);
	  	digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
          delay(2000);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
          delay(2000);
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
          delay(2000);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
          delay(2000);
        var++;
      }
       if(var == 3){
        digitalWrite(12, LOW);
     	 analogWrite(6,0);
         while(var == 0)
     	delay(2000);
 		digitalWrite(3,HIGH);
    	 delay(1000);
    	digitalWrite(3,LOW);
         Serial.println ("MODO AUTOMATICO APAGADO");
       }
      }
else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  	analogWrite(6,0);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(3,LOW);   
  var = var * 0;
    Serial.println ("MODO AUTOMATICO ENCENDIDO");
}

}

  