// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define LED1 3  // On Trinket or Gemma, suggest changing this to 1
#define LED2 1  // On Trinket or Gemma, suggest changing this to 1

//#define Rele 2  // On Trinket or Gemma, suggest changing this to 1
#define pot A2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS1 25  // Popular NeoPixel ring size
#define NUMPIXELS2 8   // Popular NeoPixel ring size

Adafruit_NeoPixel pixels1(NUMPIXELS1, LED1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, LED2, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500  // Time (in milliseconds) to pause between pixels

void setup() {
  pinMode(pot,INPUT);
  pixels1.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)

  //Serial.begin(9600);

  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  // rainbow1(1);
  // rainbow2(2);
  pixels1.clear();  // Set all pixel colors to 'off'
  pixels2.clear();  // Set all pixel colors to 'off'
  apagar1();
  apagar2();
}
// brazo 1-> 1:10
// brazo 2-> 11:18
// brazo 3-> 11:23


void corazon(int wait) {
  pixels1.clear();  // Set all pixel colors to 'off'

  for (int i = 23; i <= 25; i++) {
    pixels1.setPixelColor(i, pixels1.Color(40, 0, 0));
  }
  pixels1.show();

  delay(wait);

  for (int i = 23; i <= 25; i++) {
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
  }
  pixels1.show();

  delay(wait);
}

// Brazo 1 Ida y vuelta
void brazo1(int wait) {
  pixels1.clear();  // Set all pixel colors to 'off'
  int k = 0;
  for (int i = 16; i <= NUMPIXELS1; i++) {  // For each pixel...
    k = NUMPIXELS1 - i;
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if (k % 2 == 0) {
      pixels1.setPixelColor(k, pixels1.Color(50, 0, 0));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
      // corazon(wait*2);
    } else {
      pixels1.setPixelColor(k, pixels1.Color(0, 0, 50));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
    }
  }
  pixels1.clear();
  for (int i = 0; i <= 10; i++) {  // For each pixel...
    k = i;
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if (k % 2 == 0) {
      pixels1.setPixelColor(k, pixels1.Color(50, 0, 0));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
      // corazon(wait*2);
    } else {
      pixels1.setPixelColor(k, pixels1.Color(0, 0, 50));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
    }
  }
}

void brazo2(int wait) {
  pixels1.clear();  // Set all pixel colors to 'off'
  int k = 0;
  for (int i = 11; i <= 17; i++) {  // For each pixel...
    k = i;
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if (k % 2 == 0) {
      pixels1.setPixelColor(k, pixels1.Color(50, 0, 0));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
      // corazon(wait*2);
    } else {
      pixels1.setPixelColor(k, pixels1.Color(0, 0, 50));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
    }
  }
  pixels1.clear();  // Set all pixel colors to 'off'

  k = 0;
  for (int i = 8; i <= 15; i++) {  // For each pixel...
    k = NUMPIXELS1 - i;
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if (k % 2 == 0) {
      pixels1.setPixelColor(k, pixels1.Color(50, 0, 0));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
      // corazon(wait*2);
    } else {
      pixels1.setPixelColor(k, pixels1.Color(0, 0, 50));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
    }
  }
}

void brazo3(int wait) {
  pixels1.clear();  // Set all pixel colors to 'off'
  int k = 0;
  for (int i = 3; i <= 7; i++) {  // For each pixel...
    k = NUMPIXELS1 - i;
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if (k % 2 == 0) {
      pixels1.setPixelColor(k, pixels1.Color(50, 0, 0));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
      // corazon(wait*2);
    } else {
      pixels1.setPixelColor(k, pixels1.Color(0, 0, 50));
      pixels1.show();  // Send the updated pixel colors to the hardware.
      delay(wait);     // Pause before next pass through loop
    }
  }
}

void rainbow1(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i <= NUMPIXELS1; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / pixels1.numPixels());
      pixels1.setPixelColor(i, pixels1.gamma32(pixels1.ColorHSV(pixelHue)));
    }
    pixels1.show();
    delay(wait);
  }
}

void rinon(int wait) {
  pixels1.clear();  // Set all pixel colors to 'off'
  pixels2.clear();  // Set all pixel colors to 'off'

  pixels2.setPixelColor(2, pixels2.Color(50, 50, 0));
  pixels2.setPixelColor(3, pixels2.Color(50, 50, 0));
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(wait);
  pixels2.setPixelColor(1, pixels2.Color(50, 50, 0));
  pixels2.setPixelColor(4, pixels2.Color(50, 50, 0));
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(wait);
  pixels2.setPixelColor(0, pixels2.Color(50, 50, 0));
  pixels2.setPixelColor(5, pixels2.Color(50, 50, 0));
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(wait);

  pixels2.setPixelColor(7, pixels2.Color(50, 50, 0));
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(wait);
  pixels2.setPixelColor(6, pixels2.Color(50, 50, 0));
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(wait);
}

void rinon2(int wait) {
  pixels1.clear();  // Set all pixel colors to 'off'
  pixels2.clear();  // Set all pixel colors to 'off'

  pixels2.setPixelColor(2, pixels2.Color(50, 60, 15));
  pixels2.setPixelColor(3, pixels2.Color(50, 60, 15));
  // pixels2.show();  // Send the updated pixel colors to the hardware.
  // delay(wait);
  pixels2.setPixelColor(1, pixels2.Color(50, 60, 15));
  pixels2.setPixelColor(4, pixels2.Color(50, 60, 15));
  // pixels2.show();  // Send the updated pixel colors to the hardware.
  // delay(wait);
  pixels2.setPixelColor(0, pixels2.Color(50, 60, 15));
  pixels2.setPixelColor(5, pixels2.Color(50, 60, 15));
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(wait);
}

void rainbow2(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i <= NUMPIXELS2; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / pixels2.numPixels());
      pixels2.setPixelColor(i, pixels2.gamma32(pixels2.ColorHSV(pixelHue)));
    }
    pixels2.show();
    delay(wait);
  }
}

void apagar1() {
  for (int i = 0; i <= NUMPIXELS1; i++) {  // For each pixel...
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
  }
  pixels1.show();  // Send the updated pixel colors to the hardware.
  delay(100);
}

void apagar2() {
  for (int i = 0; i <= NUMPIXELS2; i++) {  // For each pixel...
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
  }
  pixels2.show();  // Send the updated pixel colors to the hardware.
  delay(50);
}

void loop() {

  // rinon2(100);
  // delay(1000);

  //Serial.println(analogRead(A2));
  int potValue = analogRead(pot);

  // Mapea el valor del potenciómetro al rango de brillo del LED (0 a 255)
  int brightness = map(potValue, 0, 1023, 0, 1023);
//   int brightness = potValue;

brightness= 500;
  if (brightness > 300) {
    apagar1();
    apagar2();
  }
  if (brightness > 300 and brightness < 800) {
    corazon(500);
    brazo1(50);
    corazon(500);
    brazo2(50);
    corazon(500);
    brazo3(50);
    rinon(100);
    rinon(100);
  }
  if (brightness > 799 and brightness < 1024) {
    corazon(500);
    brazo1(50);
    corazon(500);
    brazo2(50);
    corazon(500);
    brazo3(50);
    delay(50);
    rinon2(100);
    delay(50);
    corazon(500);
      apagar2();

    rinon2(100);
    delay(50);
    corazon(500);
  apagar2();

    rinon2(100);
    delay(200);
  }
  apagar1();
  apagar2();
}