
void audio(int wait) {
  static float level[7];
  static byte heat[6][7];
   
  if (fft1024.available()) {
    level[6] =  fft1024.read(0,   1  );
    level[5] =  fft1024.read(2,   6  );
    level[4] =  fft1024.read(7,   15 );
    level[3] =  fft1024.read(16,  32 );
    level[2] =  fft1024.read(33,  66 );
    level[1] =  fft1024.read(67,  131);
    level[0] =  fft1024.read(132, 511);
     
    for(int x = 0;x < 7;x++) {
      for(int yI = 0;yI < items[x];yI++) {
        int y = item_start[x] - yI;
        double mult = (1.0 * (items[x] - yI)) / (1.0 * items[x]);
        int pixel = layout[y][x];
        if (pixel != INUL) {
          heat[y][x]  = qadd8(heat[y][x], level[x] * mult * 20);
          leds[pixel] =  CHSV(x*33, 255, heat[y][x]);
          heat[y][x]  = qsub8(heat[y][x], 120);
        }
      }
    }
  }
   
  FastLED.show();
 
  FastLED.delay(wait);
}