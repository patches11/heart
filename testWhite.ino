void testWhite() {
   for(int pixel = 0;pixel< PIXEL_COUNT;pixel++) {
    leds[pixel] = CRGB::White;
  }
  
  FastLED.show();
  
  FastLED.delay(200);
}
