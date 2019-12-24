void setup() {
  pinMode(7,OUTPUT); //r
  pinMode(8,OUTPUT); //g
  pinMode(9,OUTPUT); //b
  digitalWrite(7,LOW);  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  Serial.begin(9600);
  char ans;
}

void loop() {
  if (Serial.available() > 0)
  {
    c = Serial.read()
    if (c = 'r'){
      digitalWrite(7, HIGH);
    }
    else if (c == 'g') {
      digitalWrite(8, HIGH);
    }
    else if (c == 'b') {
      digitalWrite(9, HIGH);
    }
    delay(2000);
    //All should light up after the delay
    {
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
    }
  }
}
