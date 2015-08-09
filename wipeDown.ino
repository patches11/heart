void wipeDown(int wait) {
  uint32_t color;
  
  int paletteShift = (millis() % 100000) / 30;
  
  for(int x = 0;x < 7;x++) {
    for(int y = 0;y < 6;y++) {
      int pixel = layout[y][x];
      if(pixel != INUL) {
        color = palette[(y*15 + paletteShift) % 256];
        leds[pixel].setRGB((color >> 16) & 0x0000FF, (color >> 8) & 0x0000FF, color & 0x0000FF);
      }  
    }
  }
  FastLED.show();
  
  FastLED.delay(wait);
}