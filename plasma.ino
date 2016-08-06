
void plasma(int wait) { 
  uint32_t color;
  
  int paletteShift = (millis() % 100000) / 30;
 
  for(uint16_t x = 0;x < 240;x+=32) {
    for(uint16_t y = 0;y < 240;y+=32) {
      uint8_t pix_x = x / 32;
      uint8_t pix_y = y / 32;
      uint8_t pixel = layout[pix_y][pix_x];
      if (pixel != INUL) {
        color = palette[((buffer[x+16][y+16] + paletteShift) % 256)];
        leds[pixel].setRGB((color >> 16) & 0x0000FF, (color >> 8) & 0x0000FF, color & 0x0000FF);
      }
    }
  }
  FastLED.show();
  
  FastLED.delay(wait);
}