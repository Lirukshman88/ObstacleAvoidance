int enableleft = 5;
int enableright= 10;
int motorleft = 6;
int motorleft2 = 7;
int motorright = 3;
int motorright2 = 4;
int trigC = 8; 
int echoC = 9; 
int durationC;
int trigL = 13;
int echoL = 2;
int durationL; 
int trigR = 11;
int echoR = 12;
int durationR;
 
void setup() {
  pinMode (10, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigC, LOW);
  delayMicroseconds(2);
  digitalWrite(trigC, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigC, LOW);
  durationC = pulseIn(echoC, HIGH);

  digitalWrite(trigL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigL, LOW);
  durationL = pulseIn(echoL, HIGH);

  digitalWrite(trigR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigR, LOW);
  durationR = pulseIn(echoR, HIGH);

  Serial.println(durationC);
  Serial.println(durationL);
  Serial.println(durationR);

if (durationC > 1500)
    {
    analogWrite(5, 255);
    analogWrite(10, 251);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
else if(durationC < 1500)
{
  if(durationL > durationR)
  {
    analogWrite(5, 255);
    analogWrite(10, 251);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW); 
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(500);
  }
else if(durationR > durationL)
{
    analogWrite(5, 255);
    analogWrite(10, 251);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH); 
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(500);
  }   
}   
  }
   
  
  
