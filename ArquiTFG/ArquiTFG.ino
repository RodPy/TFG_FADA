// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define LED        0 // On Trinket or Gemma, suggest changing this to 1
#define SENSOR     4 // On Trinket or Gemma, suggest changing this to 1
#define BTN_1     1 // On Trinket or Gemma, suggest changing this to 1
#define BTN_2     2 // On Trinket or Gemma, suggest changing this to 1
#define BTN_3     3 // On Trinket or Gemma, suggest changing this to 1


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 67 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
//    pinMode(SENSOR, INPUT_PULLUP);
  pinMode(SENSOR, INPUT);
  pinMode(BTN_1 , INPUT);
  pinMode(BTN_2 , INPUT);
  pinMode(BTN_3 , INPUT);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  Serial.begin(9600);

  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

}

int led=0;

void secuenciaLed(int R, int G, int B, int timeDelay){
  
  for(int i=0; i<=NUMPIXELS/2; i++) { 
    led= NUMPIXELS-i;
    pixels.setPixelColor(i, pixels.Color(R, G, B));
    pixels.setPixelColor(led, pixels.Color(R, G, B));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(timeDelay); // Pause before next pass through loop
    }
  
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<=NUMPIXELS; i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show();
    delay(wait);
  }
}

void loop() {
  
  pixels.clear(); // Set all pixel colors to 'off'

  
  // Apagado
  if (digitalRead(BTN_1)){
    secuenciaLed(0, 0, 0, 10);

    
  }

  // Secuencia de Alimentacion
  if (digitalRead(BTN_2)){
    Serial.println(analogRead(0));
    if (analogRead(0)<100){

      if (digitalRead(SENSOR)){
            Serial.println("sensor ");

        secuenciaLed(0, 255, 0, 100);
        secuenciaLed(0, 255, 0, 100);

        

      }
      else{ 
                    Serial.println("NOsensor ");
     
        secuenciaLed(255, 0, 0, 100);
        secuenciaLed(255, 0, 0, 100);

        
      }
    }

    else{
      rainbow(1);
    }
    
  }

  // Rayos X
  if (digitalRead(BTN_3)){
    secuenciaLed(255, 255, 255, 10);
    
  }
  
//  delay(100); // Pause before next pass through loop

}
