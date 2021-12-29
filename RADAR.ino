  //Libreria Servo
#include <Servo.h>
//Pin del sensore ultrasuoni
const int trigPin = 10;
const int echoPin = 13;
//Pin del Piezo
const int piezo = 8;
//Variabili varie
long duration;
int distance;
Servo myServo; //Oggetto per controllare il servo
void setup() {
  pinMode(trigPin, OUTPUT); //Roba in output
  pinMode(echoPin, INPUT); //Roba in input
  Serial.begin(9600);
  myServo.attach(12); //Pin servo
}
void loop() {
  //Ruota il servo da 15 a 165 gradi
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();  //Qui fa roba con la funzione per calcolare la distanza con il sensore
  Serial.print(i); //Stampiamo i dati del caso sulla seriale
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  if (distance < 8){
   tone(piezo, 750, 100);
   delay(90);
   tone(piezo, 0, 100);
  }
 }
  // Fa di nuovo la stessa cosa come fa un radar
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  if (distance < 8){
   tone(piezo, 750, 100);
   delay(90);
   tone(piezo, 0, 100);
  }
 }
}
//Funzione per calcolare la distanza (Fonte: docum. sens. arduino)
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);  //Ho sostituito i nomi dei pin nelle varie righe corrispondenti a quelli che ho messo sopra
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
