// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define LED        4 // On Trinket or Gemma, suggest changing this to 1
#define LED1       2 // On Trinket or Gemma, suggest changing this to 1


#define BTN_1     3 // On Trinket or Gemma, suggest changing this to 1
#define BTN_2     5 // On Trinket or Gemma, suggest changing this to 1

#define NUMPIXELS 8 // Popular NeoPixel ring size
#define NUMPIXELS1 12 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1(NUMPIXELS1, LED1, NEO_GRB + NEO_KHZ800);


bool bandera = false;


void apagar1(int r, int g, int b) {
  pixels.clear(); // Set all pixel colors to 'off'

  for (int i = 0; i <= NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(100);
  }
}

void apagar2(int r, int g, int b) {
  pixels1.clear(); // Set all pixel colors to 'off'

  for (int i = 0; i <= 12; i++) { // For each pixel...
    pixels1.setPixelColor(i, pixels1.Color(r, g, b));
  }
      pixels1.show();   // Send the updated pixel colors to the hardware.
    delay(10);
}

void setup() {
  //    pinMode(SENSOR, INPUT_PULLUP);
  pinMode(BTN_1 , INPUT);
  pinMode(BTN_2 , INPUT);

  //  pinMode(0,OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  Serial.begin(9600);
}

void loop() {

  Serial.print("BTN_1->");
  Serial.println(digitalRead(BTN_1));
  //  rinon(500);
  Serial.print("BTN_2->");
  Serial.println(digitalRead(BTN_2));

  //
  if (digitalRead(BTN_1)) {
    Serial.println("Habilitado");

    if (digitalRead(BTN_2)) {
      Serial.println("Color 2");
      apagar1(100, 50, 0);
      apagar2(50,50,50);
    }
    else{
       apagar1(50, 50, 0);
    }
 
  }
  else {
      apagar1(0, 0, 0);
    }

}
