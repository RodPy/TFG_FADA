// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
//#define LED        0 // On Trinket or Gemma, suggest changing this to 1
//#define SENSOR     4 // On Trinket or Gemma, suggest changing this to 1
//#define BTN_1     1 // On Trinket or Gemma, suggest changing this to 1
//#define BTN_2     2 // On Trinket or Gemma, suggest changing this to 1
//#define BTN_3     3 // On Trinket or Gemma, suggest changing this to 1

#define LED        8 // On Trinket or Gemma, suggest changing this to 1
#define LED2        5  // On Trinket or Gemma, suggest changing this to 1

#define sw        4 // On Trinket or Gemma, suggest changing this to 1

#define SENSOR     9 // On Trinket or Gemma, suggest changing this to 1
#define BTN_1     7 // On Trinket or Gemma, suggest changing this to 1
#define BTN_2     3 // On Trinket or Gemma, suggest changing this to 1
#define BTN_3     2 // On Trinket or Gemma, suggest changing this to 1
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 81 //  APARATO DIGESTIVO Popular NeoPixel ring size
#define NUMPIXELS2 63 // PARED Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, LED2, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels
 bool bandera = false;

void blink() {
  bandera = true;
      Serial.println("TRUE ");

}
void setup() {
  //    pinMode(SENSOR, INPUT_PULLUP);
  pinMode(SENSOR, INPUT);
  pinMode(BTN_1 , INPUT);
  pinMode(BTN_2 , INPUT);
  pinMode(BTN_3 , INPUT);
  pinMode(sw , INPUT);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(sw), blink, CHANGE);
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  // rainbow2(0.1);
  rainbow(0.1);
// rainbow3();
}

int led = 0;

void secuenciaLed(int R, int G, int B, int timeDelay) {

  for (int i = 0; i <= NUMPIXELS ; i++) {
    // led = NUMPIXELS - i;
    pixels.setPixelColor(i, pixels.Color(R, G, B));
        pixels2.setPixelColor(i, pixels2.Color(R, G, B));

    // pixels.setPixelColor(led, pixels.Color(R, G, B));
    //     pixels2.setPixelColor(led, pixels2.Color(R, G, B));

    pixels.show();   // Send the updated pixel colors to the hardware.
        pixels2.show();   // Send the updated pixel colors to the hardware.

    delay(timeDelay); // Pause before next pass through loop
  }

}

void secuenciaLed2(int R, int G, int B, int timeDelay) {

  for (int i = 0; i <= NUMPIXELS2 / 2; i++) {
    led = NUMPIXELS2 - i;
    pixels2.setPixelColor(i, pixels2.Color(R, G, B));
    pixels2.setPixelColor(led, pixels2.Color(R, G, B));
    pixels2.show();   // Send the updated pixel colors to the hardware.
    delay(timeDelay); // Pause before next pass through loop
  }

}

void rainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue <  65536; firstPixelHue += 256) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    delay(wait);
  }
}

void rainbow2(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i <= NUMPIXELS2; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / pixels2.numPixels());
      pixels2.setPixelColor(i, pixels2.gamma32(pixels2.ColorHSV(pixelHue)));
    }
    pixels2.show();
    pixels.show();
    delay(wait);
  }
}
void rainbow3() {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i <= NUMPIXELS; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / pixels2.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));

      pixels2.setPixelColor(i, pixels2.gamma32(pixels2.ColorHSV(pixelHue)));
    }
        pixels.show();
        pixels2.show();
        delay(0.1);
   
  }
}

void secuenciaLed4(int R, int G, int B, int timeDelay) {

  for (int i = 0; i <= NUMPIXELS; i++) {
    led = NUMPIXELS2 - i;
    pixels.setPixelColor(i, pixels.Color(R, G, B));
    if (i <=NUMPIXELS2){
      pixels2.setPixelColor(i, pixels2.Color(R, G, B)); 
      pixels2.setPixelColor(led, pixels2.Color(R, G, B));

    } 
    pixels2.show();   // Send the updated pixel colors to the hardware.
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(timeDelay); // Pause before next pass through loop
  }

}
void loop() {

  pixels.clear(); // Set all pixel colors to 'off'
  pixels2.clear(); // Set all pixel colors to 'off'


  // Apagado
  if (digitalRead(BTN_1)) {
    Serial.println("BTN_1 ");
    pixels.setPixelColor(led, pixels.Color(0, 0, 0));
    pixels2.setPixelColor(led, pixels.Color(0, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    pixels2.show();   // Send the updated pixel colors to the hardware.


  }

  // Secuencia de Alimentacion
  if (digitalRead(BTN_2)) {
    Serial.println("BTN_2 ");
    Serial.println(analogRead(0));
    Serial.println("BTN -> ");
    Serial.print(digitalRead(sw));
    
    if (digitalRead(sw)) {
      bandera = false;
            Serial.println("false ");

      if (digitalRead(SENSOR)) {
        Serial.println("sensor ");

        secuenciaLed4(0, 150, 0, 80);
      }
      else {
        Serial.println("NOsensor ");

        secuenciaLed4(150, 0, 0, 80);


      }
      delay(100);
    }

    else {
      Serial.println("No Comida ");

      for (int i = 0; i <= NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 50, 0));
        pixels2.setPixelColor(i, pixels2.Color(50, 50, 0));
      }
      pixels.show();   // Send the updated pixel colors to the hardware.
      pixels2.show();   // Send the updated pixel colors to the hardware.
      delay(2000);
      for (int i = 0; i <= NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels2.setPixelColor(i, pixels.Color(0, 0, 0));

      }
      pixels.show();   // Send the updated pixel colors to the hardware.
      pixels2.show();   // Send the updated pixel colors to the hardware.

      delay(2000);

    }

  }

  // Rayos X
  if (digitalRead(BTN_3)) {
    Serial.println("BTN_3 ");

    for (int i = 0; i <= NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(50, 50, 50));
      pixels2.setPixelColor(i, pixels.Color(50, 50, 50));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    pixels2.show();   // Send the updated pixel colors to the hardware.

  }


}
