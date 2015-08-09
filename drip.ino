

void drip(int wait) {
  boolean done = true;
  boolean move_step = false;
  static double state[6][7];

  random16_add_entropy( random());

  // fade to black
  if (love_mode == 0) {
    mode_start_time = millis();
    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 6;y++) {
        int pixel = layout[y][x];
        state[y][x] = -3.0;   
        if (pixel != INUL) {
          newColor[pixel][0] = 0;
          newColor[pixel][1] = 0;
          newColor[pixel][2] = 0;
        }
      }
    }
    love_mode++;
  } else if (love_mode == 1 ) {
    for(int pixel = 0;pixel < PIXEL_COUNT;pixel++) {
      leds[pixel].setHSV(prevColor[pixel][0], prevColor[pixel][1], prevColor[pixel][2]);
      
      for(int i =  0;i<3;i++) {
        if (newColor[pixel][i] > prevColor[pixel][i]) {
          prevColor[pixel][i]++;
          done = false;
        } else if (newColor[pixel][i] < prevColor[pixel][i]) {
          prevColor[pixel][i]--;
          done = false;
        }
      }
    }
    if (done) {
      love_mode++;
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
          Serial.print("x: ");
          Serial.print(x);
          Serial.print(", y: ");
          Serial.print(y);
          Serial.print(", state: ");
          Serial.println(state[y][x]);

          for(int i = max(0, floor(state[y][x]) - 1);i <= min(5, floor(state[y][x]) + 2);i++) {
            int pixel = layout[i][x];
            if (i >= 0 && pixel != INUL) {
              Serial.print("pixel y: ");
              Serial.print(i);
              Serial.print(", ease input: ");
              Serial.print(255-128*abs(state[y][x]-i));
              Serial.print(", ease output: ");
              Serial.println(ease8InOutCubic(255-128*abs(state[y][x]-i)));
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