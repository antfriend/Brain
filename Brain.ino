/*
  Brain

  It's a brain.
*/

long randNumber;
int directionation;

void writePin(int pin, bool value)
{
  switch (pin){
    case 10://blue
      digitalWrite(12,value);
      break;
    case 11://blue
      digitalWrite(13,value);
      break;
    case 12:// ?
      digitalWrite(A0,value);
      break;
    case 13:// red back
      digitalWrite(A1,value);
      break;
    case 14:// ?
      digitalWrite(A2,value);
      break;
    case 15:
      digitalWrite(A3,value);
      break;
    case 16:
      digitalWrite(A4,value);
      break;
      
    default://     0-9
      //0-3 blue frontal
      //4-7 red frontal - 7 shorts
      //8-9 blue mid back
      if(value < 16){
        digitalWrite(pin,value);
      }
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

void all_off()
{
  for (int i = 0; i <= 16; i++) {
    writePin(i, LOW);
  }
}

void cycle_up(int from, int to, long milis, bool state)
{
  for (int i = from; i <= to; i++) {
    writePin(i, state);
    delay(milis);
  }
}

void cycle_down(int from, int to, long milis, bool state)
{
  for (int i = from; i >= to; i--) {
    writePin(i, state);
    delay(milis);
  }
}

void loop() 
{
  all_off();
  randNumber = random(50, 100);
  delay(randNumber * 10);

  int _low = 0;
  int _high = 16;
  
  cycle_up(_low, _high, randNumber, HIGH);
  cycle_up(_low, _high, randNumber, LOW);

  cycle_down(_high, _low, randNumber, HIGH);
  cycle_down(_high, _low, randNumber, LOW);

}
