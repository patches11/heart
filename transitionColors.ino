boolean transitionColors() {
  boolean done = true;
  
  for(int pixel = 0;pixel < PIXEL_COUNT;pixel++) {       
    leds[pixel].setHSV(prevColor[pixel][0], prevColor[pixel][1], prevColor[pixel][2]);
    
    for(int i = 0;i < 3;i++) {
      if (newColor[pixel][i] > prevColor[pixel][i]) {
        prevColor[pixel][i]++;
        done = false;
      } else if (newColor[pixel][i] < prevColor[pixel][i]) {
        prevColor[pixel][i]--;
        done = false;
      }
    }
  }
 
 return done; 
}
