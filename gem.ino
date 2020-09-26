#include <Adafruit_CircuitPlayground.h>
int presets[3][2][3] = { {{196, 97, 140}, {188, 64, 119}}, {{97, 153, 59}, {126, 186, 181}}, {{255, 178, 0}, {134, 26, 34}}
};
int preset = 0;

void setup() {
  Serial.begin(9600); CircuitPlayground.begin();
}
void loop() {
  float total = abs(CircuitPlayground.motionY()) + abs(CircuitPlayground.motionZ());
  //Serial.println(total);

  if (total > 13) {
    preset = (preset+1)%3; 


    }
    if (total < 10) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
      delay(1);
 
    }

  }

}
