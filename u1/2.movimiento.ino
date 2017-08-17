const int LEDPin= 13; // Pin de diodo LED incorporado
const int PIRPin= 2; // Pin de entrada
 
void setup(){
pinMode(LEDPin, OUTPUT); // Configuramos el pin como salida
pinMode(PIRPin, INPUT); // Configuramos el pin como entrada
Serial.begin(9600);
}
 
void loop(){
int value= digitalRead(PIRPin); // Leemos el pin 
if (value == HIGH) { // Si es un valor alto:
digitalWrite(LEDPin, HIGH); // Encendemos el LED
Serial.println("activo");
delay(1000);
} else { // Si es un valor bajo:
digitalWrite(LEDPin, LOW); // Apagamos el LED
Serial.println("desactivo");
delay(1000);
}
}

