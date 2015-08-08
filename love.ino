  const uint8_t L[6][7] = {
   INUL,   0,   0,INUL,   1,   0,INUL,
      0,   0,   0,   0,   1,   0,   0,
      0,   0,   0,   0,   1,   0,   0,
   INUL,   0,   0,   0,   1,   0,INUL,
   INUL,INUL,   1,   1,   1,INUL,INUL,
   INUL,INUL,INUL,   0,INUL,INUL,INUL
  };
  
   const uint8_t O[6][7] = {
   INUL,   0,   0,INUL,   0,   0,INUL,
      0,   0,   1,   1,   1,   0,   0,
      0,   0,   1,   0,   1,   0,   0,
   INUL,   0,   1,   0,   1,   0,INUL,
   INUL,INUL,   1,   1,   1,INUL,INUL,
   INUL,INUL,INUL,   0,INUL,INUL,INUL
  };
  
     const uint8_t V[6][7] = {
   INUL,   0,   0,INUL,   0,   0,INUL,
      0,   0,   1,   0,   1,   0,   0,
      0,   0,   1,   0,   1,   0,   0,
   INUL,   0,   1,   0,   1,   0,INUL,
   INUL,INUL,   0,   1,   0,INUL,INUL,
   INUL,INUL,INUL,   0,INUL,INUL,INUL
  };
  
       const uint8_t E[6][7] = {
   INUL,   0,   1,INUL,   1,   0,INUL,
      0,   0,   0,   0,   1,   0,   0,
      0,   0,   1,   1,   1,   0,   0,
   INUL,   0,   0,   0,   1,   0,INUL,
   INUL,INUL,   1,   1,   1,INUL,INUL,
   INUL,INUL,INUL,   0,INUL,INUL,INUL
  };

void love(int wait) {
  boolean done = true;
  
  for(int pixel = 0;pixel< PIXEL_COUNT;pixel++) {
   
    for(int i =  0;i<3;i++) {
      if (newColor[pixel][i] != prevColor[pixel][i]) {
        done = false;
      }
    }
    
    leds[pixel].setHSV(prevColor[pixel][0], prevColor[pixel][1], prevColor[pixel][2]);
    
    for(int i =  0;i<3;i++) {
      if (newColor[pixel][i] > prevColor[pixel][i]) {
        prevColor[pixel][i]++;
      } else if (newColor[pixel][i] < prevColor[pixel][i]) {
        prevColor[pixel][i]--;
      }
    }
  }
  
  FastLED.show();
  
  if (done) {
    //in letter
    love_mode = (love_mode + 1) % 4;

    random16_add_entropy( random());
    
    tempCol[0] = random8();
    tempCol[1] = random8(225,256);
    tempCol[2] = random8(225,256);
    
    //out of letter
    tempColB[0] = random8();
    tempColB[1] = random8(175,200);
    tempColB[2] = random8(175,200);
    
    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 6;y++) {
        
        if((love_mode == 1 && L[y][x] == 1) or (love_mode == 2 && O[y][x] == 1) or (love_mode == 3 && V[y][x] == 1) or (love_mode == 0 && E[y][x] == 1)) {
          int pixel = layout[y][x];
          if (pixel != INUL) {
            newColor[pixel][0] = tempCol[0];
            newColor[pixel][1] = tempCol[1];
            newColor[pixel][2] = tempCol[2];
          }
        } else {
          int pixel = layout[y][x];
          if (pixel != INUL) {
            newColor[pixel][0] = tempColB[0];
            newColor[pixel][1] = tempColB[1];
            newColor[pixel][2] = tempColB[2];
          }
        }
      }
    }
  }
  
  FastLED.delay(wait); 
}