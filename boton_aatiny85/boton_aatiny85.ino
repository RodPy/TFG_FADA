

int ledPin1 = 0;
int ledPin2 = 1;
int ledPin3 = 2;

int pulsador_0 = 3; // analogRead(1) takes place at P2
int pulsador_1 = 4; // analogRead(1) takes place at P2
int pulsador_2 = 5; // analogRead(1) takes place at P2


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1,OUTPUT);  
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);

  pinMode(pulsador_0,INPUT);  
  pinMode(pulsador_1,INPUT);   
  pinMode(pulsador_2,INPUT); 

  Serial.begin(9600);
}

void loop() {

  if(digitalRead(pulsador_0)){
    Serial.println("pulsador_1");
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);

    }

  if(digitalRead(pulsador_1)){
    Serial.println("pulsador_2");
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin3,LOW);    
    }

  if(digitalRead(pulsador_2)){
    Serial.println("pulsador_3");
    digitalWrite(ledPin3,HIGH);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin1,LOW);
    }

  delay(500);

}
