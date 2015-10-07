int ledA = 13;
int ledB = 12;
int ledC = 11;
int ledD = 10;

void setup() {                
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int inByte = 0;
  int ledPin = ledA;
  
  if (Serial.available()) {
    inByte = Serial.read();

    switch (inByte) {
      case 'a':
        ledPin = ledA;
        break;
      case 'b':
        ledPin = ledB;
        break;
      case 'c':
        ledPin = ledC;
        break;
      case 'd':
        ledPin = ledD;
        break;
      default:
        break;
    }
    
    if (digitalRead(ledPin) == HIGH)
      digitalWrite(ledPin, LOW);
    else
      digitalWrite(ledPin, HIGH);
    
    Serial.write(inByte);
  }
}


