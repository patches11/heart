void randomColors(int wait) {
  for(uint8_t pixel = 0;pixel < PIXEL_COUNT;pixel++) {
    boolean done = true;
    for(uint8_t i = 0;i < 3;i++) {
      if (newColor[pixel][i] != prevColor[pixel][i]) {
        done = false;
      }
    }
    
    if (done) {
      random16_add_entropy(random());

      newColor[pixel][0] = random8();
      newColor[pixel][1] = random8(200,255);
      newColor[pixel][2] = random8(200,255);
    }
    
    leds[pixel].setHSV(prevColor[pixel][0], prevColor[pixel][1], prevColor[pixel][2]);
    
    for(uint8_t i = 0;i < 3;i++) {
      if (newColor[pixel][i] > prevColor[pixel][i]) {
        prevColor[pixel][i]++;
      } else if (newColor[pixel][i] < prevColor[pixel][i]) {
        prevColor[pixel][i]--;
      }
    }
  }
  
  FastLED.show();
 
  FastLED.delay(wait);
}