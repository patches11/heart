void startup() {

  //Red
  for(uint16_t t = 0;t < 256;t++) {
    for(uint8_t x = 0;x < 7;x++) {
      for(uint8_t y = 0;y < 6;y++) {
        uint8_t pixel = layout[y][x];
        if(pixel != INUL) {
          uint8_t r = qadd8(t, qsub8(6, x));
          leds[pixel].setHSV(0, triwave8(r), triwave8(r));
        }  
      }
    }
    FastLED.show();

    FastLED.delay(10);
    
  }

  //Green
  for(uint16_t t = 0;t < 256;t++) {
    for(uint8_t x = 0;x < 7;x++) {
      for(uint8_t y = 0;y < 6;y++) {
        uint8_t pixel = layout[y][x];
        if(pixel != INUL) {
          uint8_t r = qadd8(t, qsub8(x, 6));
          leds[pixel].setHSV(96, triwave8(r), triwave8(r));
        }  
      }
    }
    FastLED.show();

    FastLED.delay(10);
  }

  for(uint16_t t = 0;t < 256;t++) {
    for(uint8_t x = 0;x < 7;x++) {
      for(uint8_t y = 0;y < 6;y++) {
        uint8_t pixel = layout[y][x];
        if(pixel != INUL) {
          uint8_t r = qadd8(t, qsub8(5, y));
          leds[pixel].setHSV(160, triwave8(r), triwave8(r));
        }  
      }
    }
    FastLED.show();

    FastLED.delay(10);
  }

  for(int i = 0;i<27;i++) {
    leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
}