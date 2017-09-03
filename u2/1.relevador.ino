const int pinSensor = 3;
const int pinTransistor = 4;

int estado;

void setup() 
{
pinMode(pinSensor, INPUT);
pinMode(pinTransistor, OUTPUT);
digitalWrite(pinTransistor, LOW); 
}

void loop()
{
  estado= digitalRead(pinSensor);
  if(estado== HIGH){
    digitalWrite(pinTransistor,HIGH);
  }else{
    digitalWrite(pinTransistor,LOW);
  }
}

