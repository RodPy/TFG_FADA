
//int ledPin1 = 9;
//int ledPin2 = 8;
//int ledPin3 = 10;


int ledPin1 = 0;
int ledPin2 = 4;
int ledPin3 = 5;


//int pulsador_0 = 5; // analogRead(1) takes place at P2
//int pulsador_1 = 4; // analogRead(1) takes place at P2
//int pulsador_2 = 3; // analogRead(1) takes place at P2

int pulsador_0 = 1; // analogRead(1) takes place at P2
int pulsador_1 = 2; // analogRead(1) takes place at P2
int pulsador_2 = 3; // analogRead(1) takes place at P2
int sensor = 12; // analogRead(1) takes place at P2

//#include <SoftwareSerial.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1,OUTPUT);  
  pinMode(ledPin2,OUTPUT);
   pinMode(ledPin3,OUTPUT);

  pinMode(pulsador_0,INPUT);  
  pinMode(pulsador_1,INPUT);   
  pinMode(pulsador_2,INPUT); 
  pinMode(sensor,INPUT); 
//  pinMode(A0,INPUT); 


   
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);

  Serial.begin(9600);
}

void loop() {
    
    Serial.println(" ");
    Serial.print("D-> ");
    Serial.print(digitalRead(pulsador_0));
    Serial.print(" - ");
    Serial.print(digitalRead(pulsador_1));
    Serial.print(" - ");
    Serial.print(digitalRead(pulsador_2));
    Serial.print(" - ");
    Serial.print(analogRead(0));

  if(digitalRead(pulsador_0)){
    Serial.print(" - BOTON 1 ");
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);
    }

  if(digitalRead(pulsador_1)){
    Serial.print(" - BOTON 2 ");
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,LOW);
    }

  if(digitalRead(pulsador_2)){
    Serial.print(" - BOTON 3 ");
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    }

  
  if(digitalRead(sensor)){
    Serial.print(" - SENSOR ");
    digitalWrite(ledPin3,HIGH);
    }
    
  if(digitalRead(sensor)==LOW){
    Serial.print(" - noSENSOR ");
    digitalWrite(ledPin3,LOW);
    }

  delay(1000);

}
