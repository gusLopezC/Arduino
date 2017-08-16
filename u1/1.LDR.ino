int sensorReading;//Pin análogo en espera
void setup(){
 Serial.begin(9600);
 pinMode(6,OUTPUT); // 
}
void loop(){
 sensorReading=analogRead(0); //Instrucción para obtener dato analógico
 if (sensorReading<70){    //si es menor a 70 se apaga led 
 digitalWrite(6,HIGH);
 }
 else digitalWrite(6,LOW);
 Serial.println(sensorReading); 
 delay(1000);
}
