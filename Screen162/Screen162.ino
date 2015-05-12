#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 9, 8, 7, 6, 5, 4, 3, 2); //liaison 8 bits de données
int i = 0;
bool dir = true;
char *msg = "Prog de test :)"; // setup the mistery line
char *randStr;

void setup() {
	lcd.begin(16, 2); //utilisation d'un écran 16 colonnes et 2 lignes
	randStr = (char *)malloc(17 * sizeof(char));
	initRandString(randStr);
	Serial.begin(9600);
}

// size of string
int strlen(char *a)
{
	int i = -1;
	if (a != NULL)
		while (a[++i]);
	return i;
}

//print one line
void printLine(char *line, int lineNumber)
{
	for (size_t i = 0; i < strlen(line); i++)
	{
		lcd.setCursor(i, lineNumber);
		lcd.print(line[i]);
	}
}

//print one line with offset
void printLineWithOffset(char *line, int lineNumber, size_t offset)
{
	lcd.clear();
	for (size_t i = 0; i < strlen(line); i++)
	{
		lcd.setCursor(i + offset, lineNumber);
		lcd.print(line[i]);
		Serial.println(line[i]);
	}
}

//print all lines
void printerAllLines(char **lines)
{
	for (int line = 0; lines[line] != NULL; line++)
		for (int i = 0; i < strlen(lines[line]); i++)
		{
			lcd.setCursor(i, line);
			lcd.print(lines[line][i]);
		}
}

//complete all char by 0
void initRandString(char *randString)
{
	for (size_t i = 0; i < 17; i++)
		randString[i] = 0;
}

// if the char of mistery string is discovered the char is save else replace by 0
void controlString(char const *msgString, char * randString)
{
	for (size_t i = 0; i < 17; i++)
	{
		if (i < strlen(msgString) && msgString[i] != randString[i])
			randString[i] = 0;
		if (i >= strlen(msgString) && ' ' != randString[i])
			randString[i] = 0;
	}
}

void loop() {
	
	//scroll string left to right to left
	/*printLineWithOffset(msg, 0, i);
	if (i == 0)
		dir = true;
	else if (i == 16 - strlen(msg))
		dir = false;
	if (i <= 16 - strlen(msg) && i >= 0)
		i += dir ? 1 : -1;*/
	
	//find mistery string
	for (size_t i = 0; i < 17; i++)
	{
		if (randStr[i] == 0)
			randStr[i] = (char)random(32, 126);
	}
	printLine(randStr, 0);
	controlString(msg, randStr);
	delay(20);
}
