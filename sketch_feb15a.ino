#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Buttons
#define DOT_BTN 2
#define DASH_BTN 3
#define SPACE_BTN 4

// LEDs
#define LED_DOT 8
#define LED_DASH 9
#define LED_OUT 10

// Buzzer
#define BUZZER 11

String morse = "";
String message = "";

// debounce memory
bool lastDot = HIGH;
bool lastDash = HIGH;
bool lastSpace = HIGH;

void setup() {
  pinMode(DOT_BTN, INPUT_PULLUP);
  pinMode(DASH_BTN, INPUT_PULLUP);
  pinMode(SPACE_BTN, INPUT_PULLUP);

  pinMode(LED_DOT, OUTPUT);
  pinMode(LED_DASH, OUTPUT);
  pinMode(LED_OUT, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(10, 10);
  display.print("Morse Translator");
  display.setCursor(10, 30);
  display.print("Ready...");
  display.display();
}

void loop() {

  bool dotState = digitalRead(DOT_BTN);
  bool dashState = digitalRead(DASH_BTN);
  bool spaceState = digitalRead(SPACE_BTN);

  // ---------- DOT pressed ----------
  if (dotState == LOW && lastDot == HIGH) {

    digitalWrite(LED_OUT, HIGH);          // Common LED
    tone(BUZZER, 1000, 120);              // Common beep

    morse += ".";
    digitalWrite(LED_DOT, HIGH);
    delay(120);
    digitalWrite(LED_DOT, LOW);

    digitalWrite(LED_OUT, LOW);
  }

  // ---------- DASH pressed ----------
  if (dashState == LOW && lastDash == HIGH) {

    digitalWrite(LED_OUT, HIGH);
    tone(BUZZER, 1000, 360);

    morse += "-";
    digitalWrite(LED_DASH, HIGH);
    delay(360);
    digitalWrite(LED_DASH, LOW);

    digitalWrite(LED_OUT, LOW);
  }

  // ---------- SPACE pressed ----------
  if (spaceState == LOW && lastSpace == HIGH) {

    digitalWrite(LED_OUT, HIGH);
    tone(BUZZER, 1000, 150);

    char letter = decodeMorse(morse);
    message += letter;

    display.clearDisplay();
    display.setCursor(0, 20);
    display.print(message);
    display.display();

    delay(150);
    digitalWrite(LED_OUT, LOW);

    morse = "";
  }

  lastDot = dotState;
  lastDash = dashState;
  lastSpace = spaceState;

  delay(20);   // debounce
}

// -------- Morse Decoder --------
char decodeMorse(String code) {

  // Letters
  if (code == ".-") return 'A';
  if (code == "-...") return 'B';
  if (code == "-.-.") return 'C';
  if (code == "-..") return 'D';
  if (code == ".") return 'E';
  if (code == "..-.") return 'F';
  if (code == "--.") return 'G';
  if (code == "....") return 'H';
  if (code == "..") return 'I';
  if (code == ".---") return 'J';
  if (code == "-.-") return 'K';
  if (code == ".-..") return 'L';
  if (code == "--") return 'M';
  if (code == "-.") return 'N';
  if (code == "---") return 'O';
  if (code == ".--.") return 'P';
  if (code == "--.-") return 'Q';
  if (code == ".-.") return 'R';
  if (code == "...") return 'S';
  if (code == "-") return 'T';
  if (code == "..-") return 'U';
  if (code == "...-") return 'V';
  if (code == ".--") return 'W';
  if (code == "-..-") return 'X';
  if (code == "-.--") return 'Y';
  if (code == "--..") return 'Z';

  // Numbers
  if (code == "-----") return '0';
  if (code == ".----") return '1';
  if (code == "..---") return '2';
  if (code == "...--") return '3';
  if (code == "....-") return '4';
  if (code == ".....") return '5';
  if (code == "-....") return '6';
  if (code == "--...") return '7';
  if (code == "---..") return '8';
  if (code == "----.") return '9';

  return '?';
}

