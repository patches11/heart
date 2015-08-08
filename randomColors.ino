void randomColors(int wait) {
  for(int pixel = 0;pixel< PIXEL_COUNT;pixel++) {
    boolean done = true;
    for(int i = 0;i < 3;i++) {
      if (newColor[pixel][i] != prevColor[pixel][i]) {
        done = false;
      }
    }
    
    if (done) {
      random16_add_entropy( random());

      newColor[pixel][0] = random8();
      newColor[pixel][1] = random8(200,256);
      newColor[pixel][2] = random8(200,256);
    }
    
    leds[pixel].setHSV(prevColor[pixel][0], prevColor[pixel][1], prevColor[pixel][2]);
    
    for(int i = 0;i < 3;i++) {
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