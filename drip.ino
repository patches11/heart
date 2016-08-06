void drip(int wait) {
  boolean done = true;
  boolean move_step = false;
  static double state[6][7];
 
  random16_add_entropy( random());
 
  // fade to black
  if (love_mode == 0 ) {
    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 6;y++) {
        state[y][x] = -3.0;   
      }
    }
    for(int pixel = 0;pixel < PIXEL_COUNT;pixel++) {
      leds[pixel].fadeToBlackBy( 8 );
      if (leds[pixel]) {
        done = false;
      }
    }
    if (done) {
      love_mode = 2;
    }
  } else if (love_mode == 2) {
    for(int x = 0;x < 7;x++) {
      boolean new_drip = false;
      if(random16() < 500) {
        new_drip = true;
      }
      for(int y = 0;y < 6;y++) {
        if (state[y][x] < -2.0 && new_drip) {
          state[y][x] = -1.0;
          new_drip = false;
        } else if (state[y][x] > -2.0) {
          state[y][x] += 0.002*wait;
        }
        if (state[y][x] > 8.0) {
          state[y][x] = -3.0;
        }
        int pixel = layout[y][x];
        if (pixel != INUL) {
          leds[pixel] = CRGB::Black;
        }
      }
    }
    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 6;y++) {
        if (state[y][x] > -2.0) {
 
          for(int i = max(0, floor(state[y][x]) - 1);i <= min(5, floor(state[y][x]) + 2);i++) {
            int pixel = layout[i][x];
            if (i >= 0 && pixel != INUL) {
              leds[pixel] += CHSV( 160, 255, ease8InOutCubic(255-128*abs(state[y][x]-i)));
            }
          }
        }
         
      }
    }
  }
   
  FastLED.show();
 
  FastLED.delay(wait);
}