#include <FastLED.h>

#define NUM_LEDS 100
#define DATA_PIN 5
#define CHARS 6
#define CHAR_MAX_LEDS 21

const int pos[CHARS][CHAR_MAX_LEDS] = {
  {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 },
  { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, -1, -1, -1, -1, -1, -1, -1 },
  { 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, -1, -1, -1, -1, -1, -1 },
  { 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, -1, -1, -1, -1 },
  { 67, 68, 69, 70, 71, 72, 73, 74, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
  { 75, 76, 77, 78, 79, 80, 81, 82, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
};

const CRGB colors[] = {
  0xff0000, 0xff4000, 0xff8000, 0xffc000,
  0xffff00, 0xc0ff00, 0x80ff00, 0x40ff00,
  0x00ff00, 0x00ff40, 0x00ff80, 0x00ffc0,
  0x00ffff, 0x00c0ff, 0x0080ff, 0x0040ff,
  0x0000ff, 0x4000ff, 0x8000ff, 0xc000ff,
  0xff00ff, 0xff00c0, 0xff0080, 0xff0040
};

CRGB leds[NUM_LEDS];
int ptr = 0;

void setup() { 
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() { 
  int p;

  for (int i = 0; i < CHARS; i++) {
    p = (ptr + i) % 24;
    for (int j = 0; j < CHAR_MAX_LEDS; j++) {
      if (pos[i][j] != -1) {
        leds[pos[i][j]] = colors[p];
      }
    }
  }
  FastLED.show();
  delay(100);
  ptr--;
  ptr = (ptr == -1) ? 23 : ptr;
}
