#include "LPD8806.h"
#include "SPI.h"
#include "math.h"

// Screaming Knight LED Code
// Brandon Duffany - June 2012
// Note: This is illegal by FRC standards ...

/*****************************************************************************/

int dataPin1 = 2;
int clockPin1 = 3;

int dataPin2 = 5;
int clockPin2 = 6;

int di_1 = 8;
int di_2 = 9;
int di_3 = 10;

const int ns = 1; // Number of LPD8806 strips
LPD8806 strips[ns];

uint8_t alliance;

const int ac_red =  0;
const int ac_blue = 1;

const int chase = 0;
const int fade = 1;

void setup() {
  
  // Digital inputs from robot (bits of resolution for LED states)
  
  pinMode(di_1, INPUT);
  pinMode(di_2, INPUT);
  
  randomSeed(analogRead(0));
  alliance = random(2);
  
  // Construct each strip here
  
  strips[0] = LPD8806(18, dataPin1, clockPin1);
  strips[1] = LPD8806(14, dataPin2, clockPin2);
  
  for (int i = 0; i < ns; i++) {
    strips[i].begin();
    strips[i].show();
  }
}

void loop() { 
  
  // Reading digital inputs
  uint8_t bit1 = digitalRead(di_1);
  uint8_t bit2 = digitalRead(di_2);
  
  // Create a base-10 state from the bits
  uint8_t led_mode = bit1 + 2 * bit2;
  
  // int alliance = digitalRead(di_3);
  
  switch(led_mode) {
    case 0:
      pulse_lights(2); // no signal from relay; pulse alliance color
      break;
    case 1:
      single_chase(0, color(0,127,0)); // chase green pixel
      break;
    case 2:
      gather_lights(); // orange pixels chase & fade
      break;
    case 3: 
      double_chase(color(0, 0, 30), color(127, 127, 127));
      break;
    default:
      for (int i = 0; i < ns; i++) {
        set_all_pixels(strips[i], 0);
        strips[i].show();
        delay(100);
      }
      break;
  }
  // delay(50) // optional delay
}

void pulse_lights(float period) {
  int brightness = (int) (67 + 60 * sin(6.28 * millis() / 1000 / period)); 
  
  for (int i = 0; i < ns; i++) {
    set_all_pixels(strips[i], strips[0].Color(brightness * alliance, 0, brightness * (1 - alliance)));
    strips[i].show();
  }
}

void double_chase(uint32_t bg, uint32_t pulse) {
  static int cur_px[ns];
  
  for (int i = 0; i < ns; i++) {
    set_all_pixels(strips[i], bg);
    strips[i].setPixelColor(cur_px[i], pulse);
    strips[i].setPixelColor(strips[i].numPixels() - 1 - cur_px[i], pulse);
    cur_px[i] += 1;
    strips[i].show();
    
    delay(36);
    
    if (cur_px[i] > strips[i].numPixels()) {
      strips[i].setPixelColor(strips[i].numPixels() - 1, bg);
      strips[i].setPixelColor(0, bg);
      strips[i].show();
      delay(10);
      cur_px[i] = 0;
    }
  }
}

void single_chase(uint32_t bg, uint32_t pulse) {
  static int cur_px[ns];
  
  for (int i = 0; i < ns; i++) {
    set_all_pixels(strips[i], bg);
    strips[i].setPixelColor(cur_px[i], pulse);
    cur_px[i] += 1;
    strips[i].show();
    
    delay(20);
    
    if (cur_px[i] > strips[i].numPixels()) {
      strips[i].setPixelColor(strips[i].numPixels() - 1, bg);
      strips[i].show();
      delay(500);
      cur_px[i] = 0;
    }
  }
}

void gather_lights() {
  
  static int states[ns];
  static int cur_px[ns];
  static int fade_val[ns];  
  
  for (int i = 0; i < ns; i++) {
    
    set_all_pixels(strips[i], 0);
    
    switch (states[i]) {
      case chase:
        
        if (cur_px[i] + 1 >= (int) (strips[i].numPixels() / 2))
          states[i] = fade;
        else
          cur_px[i] += 1;
        break;
        
      case fade:
      
        fade_val[i] += 1;
        if (fade_val[i] >= 127) {
          fade_val[i] = 0;
          states[i] = chase;
        }
        break;
    }
    
    uint32_t orange_mod = color(127 - fade_val[i], (int) ((127 - fade_val[i]) / 2), 0);
    
    strips[i].setPixelColor(cur_px[i], orange_mod);
    strips[i].setPixelColor(strips[i].numPixels() - 1 - cur_px[i], orange_mod);
    strips[i].show();
    
    delay(15);
  }
}

void set_all_pixels(LPD8806 str, uint32_t col) {
    for (int i = 0; i < str.numPixels(); i++)
      str.setPixelColor(i, col);
}

uint32_t color(int r, int g, int b) {
  return strips[0].Color(r, g, b);
}
