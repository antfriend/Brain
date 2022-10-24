/*
  Brain

  It's a brain.
*/

long randNumber;
int directionation;

void writePin(int pin, bool value)
{
  switch (pin){
    case 10:
      digitalWrite(12,value);
      break;
    case 11:
      digitalWrite(13,value);
      break;
    case 12:
      digitalWrite(A0,value);
      break;
    case 13:
      digitalWrite(A1,value);
      break;
    case 14:
      digitalWrite(A2,value);
      break;
    case 15:
      digitalWrite(A3,value);
      break;
    case 16:
      digitalWrite(A4,value);
      break;
      
    default:
      digitalWrite(pin,value);
      break;      
  }
}

void setup() {
  for (int i = 0; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  randomSeed(analogRead(5));//A5 not connected
}



void loop() {
  
  for (int i = 0; i <= 16; i++) {
    writePin(i, LOW);
  }

  randNumber = random(5, 50);

  delay(randNumber * 10);
  
  if(randNumber > 30){
      for (int i = 0; i <= 16; i++) {
        writePin(i, HIGH);
        delay(randNumber);
      }
    
      for (int i = 0; i <= 16; i++) {
        writePin(i, LOW);
        delay(randNumber);
      }
  }else{
    for (int i = 16; i >= 0; i--) {
      writePin(i, HIGH);
      delay(randNumber);
    }
  
    for (int i = 16; i >= 0; i--) {
      writePin(i, LOW);
      delay(randNumber);
    }    
  }
}
