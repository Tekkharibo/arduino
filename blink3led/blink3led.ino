int blueLed = 2;
int redLed = 0;
int greenLed = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

// full power
void rgb(bool r, bool g, bool b)
{
  if (r)
    digitalWrite(redLed, HIGH);
   else
     digitalWrite(redLed, LOW);
  if (g)
    digitalWrite(greenLed, HIGH);
   else
     digitalWrite(greenLed, LOW);
  if (b)
    digitalWrite(blueLed, HIGH);
   else
     digitalWrite(blueLed, LOW);
  
}

//variable power
void rgbVariable(int r, int g, int b)
{
  analogWrite(redLed, r);
  analogWrite(greenLed, g);
  analogWrite(blueLed, b);
  
}

void loop() {
  rgb(false, false, false);
  delay(1000);
  rgb(true, false, false);
  delay(1000);
  rgb(true, true, false);
  delay(1000);
  rgb(true, true, true);
  delay(1000);
  rgb(false, true, true);
  delay(1000);
  rgb(false, false, true);
  delay(1000);
  rgb(false, false, false);
  delay(1000);
}
