// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100
#define COOLING  5
 
// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 200

//Heating co-efficient for straight verticle heating
#define SHEATING 16

//Heating co-efficient for heating at an angle
#define AHEATING 17

//Number of verticle elements
#define VERTICLE 6

#define COOLING_RATIO 50

void fire(int wait)
{
  random16_add_entropy(random());
  // Array of temperature readings at each simulation cell
  static byte heat[6][7];
 
  // Step 1.  Cool down every cell a little
  for(int x = 0;x < 7;x++) {
    for(int y = 0;y < 6;y++) {
      heat[y][x] = qsub8( heat[y][x],  random8(0, ((COOLING * 10) / VERTICLE) + 2) * ((heat[y][x] + COOLING_RATIO) / COOLING_RATIO));
    }
  }
 
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little

    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 5;y++) {
        heat[y][x] = qadd8(heat[y][x], heat[y + 1][x] / SHEATING + (heat[y + 1][mod(x - 1, 7)] + heat[(y + 1) % 7][x] ) / AHEATING);
      }
    }
   
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    for(int x = 0;x < 7;x++) {
      if( random8() < SPARKING ) {
        heat[5-abs(x-3)][x] = qadd8( heat[5-abs(x-3)][x], random8(0,5) );
      }
    }
    
    for(int x = 0;x < 4;x++) {
      if( random8() < SPARKING ) {
        //heat[6-abs(x-3)][x] = qadd8( heat[5-abs(x-3)][x], random8(20,40) );
      }
    }
    
    for(int x = 4;x < 7;x++) {
      if( random8() < SPARKING ) {
        //heat[6-abs(x-3)][x] = qadd8( heat[5-abs(x-3)][x], random8(20,40) );
      }
    }
 
    // Step 4.  Map from heat cells to LED colors
    for(int x = 0;x < 7;x++) {
      for(int y = 0;y < 6;y++) {
        int pixel = layout[y][x];
        if (pixel != INUL) {
          leds[pixel] = HeatColor(heat[y][x]);
        }
      }
    }

    FastLED.show();

    FastLED.delay(wait);
}
