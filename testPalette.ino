
void testPalette(int wait) {
 uint32_t color;
 
 Serial.println(count % 256);
 
 for(int pixel = 0;pixel< PIXEL_COUNT;pixel++) {
   color = palette[count % 256];
   leds[pixel].setRGB((color >> 16) & 0x0000FF, (color >> 8) & 0x0000FF, color & 0x0000FF);
 }
 FastLED.show();
 
 count++;
 
 FastLED.delay(wait);
}