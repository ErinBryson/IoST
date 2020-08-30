// Libraries
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Definitions
#define        DATA_PIN  6
#define      BRIGHTNESS 70
#define     PIXEL_COUNT 50
#define MAX_STRING_SIZE 24

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, DATA_PIN, NEO_RGB + NEO_KHZ800);


void setup(){
  // Prepare data pin for NeoPixel Output
  strip.setBrightness(BRIGHTNESS);
  strip.begin();

  // Flush previous data from Strip
  clearStrip();
  
  Serial.begin(9600);

  // Force program to wait for Serial to begin
  delay(2000);
  Serial.println("Hello? Will? Can you hear me?");
  Serial.println("\nPlease input a message to be displayed.");
}

void loop(){

  // Initialize input string and stringLength
  static char userInput[MAX_STRING_SIZE];
  static int stringLength;

  // Set up counter to rotate different stand
  // by modes
  static int standByMode = 0;
  
  int delayTime = 1000;

  if (Serial.available() > 0){
    getMessage(userInput, stringLength);

    AdjustTimeDelay(delayTime, stringLength);

    clearStrip();

    for(int i = 0; i < stringLength; i++){
      switchLights(userInput[i], delayTime);  
    }

    clearStrip();

    delay(500);

    Serial.print("\nWill says: ");
    Serial.println(userInput);
    Serial.println("Message Length: " + String(stringLength));

    return;
  }

  switch(standByMode){
    // Color Wipe for Red
    case 0:
      colorWipe(strip.Color(255, 0, 0), 50);
      standByMode++;
      break;

    case 1:
      colorWipe(strip.Color(255, 0, 255), 50);
      standByMode++;
      break;

    // Color Wipe for Blue
    case 2:
      colorWipe(strip.Color(0, 0, 255), 50);
      standByMode++;
      break;

    case 3:
      colorWipe(strip.Color(255, 255, 0), 50);
      standByMode++;
      break;

    // Color Wipe for Green
    case 4:
      colorWipe(strip.Color(0, 255, 0), 50);
      standByMode++;
      break;

    // Cycle Through Rainbow
    case 5:
      rainbowCycle(5);
      standByMode = 0;
      break;
  } 
}

// Clear strip
void clearStrip(){
    for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}

// Get String from Serial Monitor
void getMessage(char str[], int& strLgth){
  int index = 0;
  
  // Get and compare each char
  char endMarker = '\n';
  char readChar;

  bool overflow = false;
  bool endOfStr = false;

  // Read in chars while serial has chars available,
  // 
  while ((Serial.available() > 0) && (overflow != true) && !endOfStr){
    readChar = Serial.read();

    if (readChar != endMarker){
      readChar = char(toupper(readChar));
      str[index] = readChar;  
      index++;

      if (index > MAX_STRING_SIZE){
        overflow = true;
      }
    }
      
    else{
      endOfStr = true; 
    }
  }

  str[index] = '\0';
  strLgth = index;
}

// Function used to switch between LED lights
void switchLights(char letter, int wait){
  switch (letter){
    case 'A':
      //Serial.println(letter);
      strip.setPixelColor(0, 255, 255, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(0, 0, 0, 0);
      strip.show();
      delay(115);
      break;
    
    case 'B':
      //Serial.println(letter);
      strip.setPixelColor(1, 0, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(1, 0, 0, 0);
      strip.show();
      delay(115);
      break;
    
    case 'C':
      //Serial.println(letter);
      strip.setPixelColor(2, 255, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(2, 0, 0, 0);
      strip.show();
      delay(115);
      break;
      
    case 'D':
      //Serial.println(letter);
      strip.setPixelColor(3, 0, 255, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(115);
      break;

    case 'E':
      //Serial.println(letter);
      strip.setPixelColor(4, 0, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(4, 0, 0, 0);
      strip.show();
      delay(115);
      break;

    case 'F':
      //Serial.println(letter);
      strip.setPixelColor(5, 255, 255, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(5, 0, 0, 0);
      strip.show();
      delay(115);
      break;

    case 'G':
      //Serial.println(letter);
      strip.setPixelColor(6, 255, 0, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(6, 0, 0, 0);
      strip.show();
      delay(115);
      break;

    case 'H':
      //Serial.println(letter);
      strip.setPixelColor(7, 50, 50, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(7, 0, 0, 0);
      strip.show();
      delay(115);
      break;

    case 'I':
      //Serial.println(letter);
      strip.setPixelColor(8, 255, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(8, 0, 0, 0);
      strip.show();
      delay(115);
      break;      

   case 'J':
      //Serial.println(letter);
      strip.setPixelColor(9, 50, 50, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(9, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'K':
      //Serial.println(letter);
      strip.setPixelColor(10, 0, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(10, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'L':
      //Serial.println(letter);
      strip.setPixelColor(11, 255, 255, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(11, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'M':
      //Serial.println(letter);
      strip.setPixelColor(12, 255, 255, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(12, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'N':
      //Serial.println(letter);
      strip.setPixelColor(13, 255, 0, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(13, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'O':
      //Serial.println(letter);
      strip.setPixelColor(14, 255, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(14, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'P':
      //Serial.println(letter);
      strip.setPixelColor(15, 255, 255, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(15, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'Q':
      //Serial.println(letter);
      strip.setPixelColor(16, 255, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(16, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'R':
      //Serial.println(letter);
      strip.setPixelColor(17, 100, 100, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(17, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'S':
      //Serial.println(letter);
      strip.setPixelColor(18, 255, 255, 250);
      strip.show();
      delay(wait);
      strip.setPixelColor(18, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'T':
      //Serial.println(letter);
      strip.setPixelColor(19, 255, 255, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(19, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'U':
      //Serial.println(letter);
      strip.setPixelColor(20, 0, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(20, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'V':
      //Serial.println(letter);
      strip.setPixelColor(21, 255, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(21, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'W':
      //Serial.println(letter);
      strip.setPixelColor(22, 0, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(22, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'X':
      //Serial.println(letter);
      strip.setPixelColor(23, 255, 255, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(23, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'Y':
      //Serial.println(letter);
      strip.setPixelColor(24, 255, 0, 0);
      strip.show();
      delay(wait);
      strip.setPixelColor(24, 0, 0, 0);
      strip.show();
      delay(115);
      break;

   case 'Z':
      //Serial.println(letter);
      strip.setPixelColor(25, 255, 0, 255);
      strip.show();
      delay(wait);
      strip.setPixelColor(25, 0, 0, 0);
      strip.show();
      delay(115);
      break;
            
    default:
      delay(wait);
      break;
  }
  delay(115);
}

// Adjust DelayTime relative to stringLength
void AdjustTimeDelay(int& DELAY, int& stringLength){
// Initial DELAY
  DELAY = 1000;
  switch(stringLength){
    // No reduction of DelayTime
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      break;
    // Reduce DelayTime by 100 milliseconds
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      DELAY -= 250;
      break;
    // Reduce DelayTime by 200 milliseconds
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      DELAY -= 500;
      break;
    // Reduce DelayTime by 300 milliseconds
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
      DELAY -= 625;
      break;
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
      DELAY -= 615;
      break;
    default:
      DELAY = 0;
      break;
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
