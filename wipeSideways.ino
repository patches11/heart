    const uint8_t layouto[7][6] = {
   INUL,   0,   1,INUL,   2,   3,INUL,
     10,   9,   8,   7,   6,   5,   4,
     11,  12,  13,  14,  15,  16,  17,
   INUL,  22,  21,  20,  19,  18,INUL,
   INUL,INUL,  23,  24,  25,INUL,INUL,
   INUL,INUL,INUL,  26,INUL,INUL,INUL
  };

void wipeSideways(int wait) {
  uint32_t color;
  
  int paletteShift = (millis() % 100000) / 30;
  
  for(int x = 0;x < 7;x++) {
    for(int y = 0;y < 6;y++) {
      int pixel = layouto[x][y];
      if(pixel != INUL) {
        color = palette[(y*15 + paletteShift) % 256];
        leds[pixel].setRGB((color >> 16) & 0x0000FF, (color >> 8) & 0x0000FF, color & 0x0000FF);
      }  
    }
  }
  FastLED.show();
  
  FastLED.delay(wait);
}