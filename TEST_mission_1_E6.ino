int RED=38;
int BLUE=6;
int VAR=A0;
int servo=42;

void setup() {
  // put your setup code here, to run once:
pinMode(RED,OUTPUT);
pinMode(BLUE,OUTPUT);
pinMode(servo,OUTPUT);
pinMode(VAR,INPUT);
analogWrite(RED,0);
analogWrite(BLUE,0);
Serial.begin(115200);
}

void loop() {
if(analogRead(VAR)>660){
Serial.println("Chaussette !!!");
analogWrite(RED,0);
analogWrite(BLUE,0);
for(int k=0;k<400;k++){
analogWrite(servo,255);
delay(2);
analogWrite(servo,0);
delay(8);}}
else{analogWrite(RED,0);analogWrite(BLUE,0);analogWrite(servo,0);}
if(analogRead(VAR)>660){
Serial.println("Chaussette !!!");
analogWrite(RED,255);
analogWrite(BLUE,255);
for(int k=0;k<400;k++){
analogWrite(servo,255);
delay(1);
analogWrite(servo,0);
delay(9);}
}
else{analogWrite(RED,0);analogWrite(BLUE,0);setServoAngle(90);}
  // put your main code here, to run repeatedly:
}

void setServoAngle(int angle) {
  int pulseWidth = map(angle, 0, 180, 500, 2500); // Convertit l'angle en durée d'impulsion en microsecondes
  int pulseWidthMicroseconds = pulseWidth / 20; // Convertit la durée d'impulsion en microsecondes en durée d'impulsion en millisecondes

  for (int i = 0; i < 100; i++) { // Envoyer 100 impulsions pour stabiliser la position
    digitalWrite(servo, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servo, LOW);
    delayMicroseconds(20000 - pulseWidth); // Période de 20 ms
  }
}
