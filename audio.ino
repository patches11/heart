
void audio(int wait) {
  static float level[7];
  static byte heat[6][7];
   
  if (fft1024.available()) {
    level[0] =  fft1024.read(0, 1);
    level[1] =  fft1024.read(2, 6);
    level[2] =  fft1024.read(7, 15);
    level[3] =  fft1024.read(16, 32);
    level[4] =  fft1024.read(33, 66);
    level[5] = fft1024.read(67, 131);
    level[6] = fft1024.read(132, 511);
     
    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 6;y++) {
        int pixel = layout[y][x];
        if (pixel != INUL) {
          heat[y][x] = qadd8(heat[y][x], level[x]*20);
          leds[pixel] = CHSV(x*33, 255, heat[y][x]);
          heat[y][x] = qsub8(heat[y][x], 60);
        }
      }
    }
  }
   
  FastLED.show();
 
  FastLED.delay(wait);
}