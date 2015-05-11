int blueLed = 3;
int redLed = 6;
int greenLed = 5;
int analogPin = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

//variable power
void rgbVariable(int r, int g, int b)
{
  analogWrite(redLed, 255 - r);
  analogWrite(greenLed, 255 - g);
  analogWrite(blueLed, 255 - b);
}

void loop() {
  int i = 0;
  int j = 0;
  int k = 0;
  int val = 0;
  bool turn = true;
  while (1)  {
    rgbVariable(i,j,k);
    delay(10);
    if ((j == 0 && k == 0) || (j == 255 && k == 255))
      i += turn ? 1 : -1;
    if ((i == 255 && k == 0) || (i == 0 && k == 255))
      j += turn ? 1 : -1;
    if ((i == 255 && j == 255) || (i == 0 && j == 0))
      k += turn ? 1 : -1;
    if (i == 255 && j == 255 && k == 255)
      turn = false;
    if (i == 0 && j == 0 && k == 0)
      turn = true;
  }
}
