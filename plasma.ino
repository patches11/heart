
void plasma(int wait) { 
  uint32_t color;
  
  int paletteShift = (millis() % 100000) / 30;
 
  for(int x = 0;x < 240;x+=32) {
    for(int y = 0;y < 240;y+=32) {
      int pix_x = x / 32;
      int pix_y = y / 32;
      int pixel = layout[pix_y][pix_x];
      if (pixel != INUL) {
        color = palette[((buffer[x+16][y+16] + paletteShift) % 256)];
        leds[pixel].setRGB((color >> 16) & 0x0000FF, (color >> 8) & 0x0000FF, color & 0x0000FF);
      }
    }
  }
  FastLED.show();
  
  FastLED.delay(wait);
}