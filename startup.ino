void startup() {
  
  for(int i = 0;i<27;i++) {
    leds[i].setRGB(255, 0, 0);
  }
  FastLED.show();

  FastLED.delay(500);

  for(int i = 0;i<27;i++) {
    leds[i].setRGB(0, 255, 0);
  }
  FastLED.show();

  FastLED.delay(500);

  for(int i = 0;i<27;i++) {
    leds[i].setRGB(0, 0, 255);
  }
  FastLED.show();

  FastLED.delay(500);

  for(int i = 0;i<27;i++) {
    leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
}