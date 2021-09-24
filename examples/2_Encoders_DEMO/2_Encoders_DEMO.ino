#include <rotaryEncoder.h>

uint8_t CLK[2] = {A0, A2};
uint8_t DT[2] = {A1, A3};

rotaryEncoder Encoder[2];

void setup() {
  for(int i = 0; i<2; i++){
    Encoder[i].setPhase(CLK[i], DT[i]);
    Encoder[i].init();
    Encoder[i].startCounter();
  }
  Serial.begin(115200);
}

void loop() {
  for(int i = 0; i<2; i++){
    Encoder[i].run();
    Serial.println("Encoder" + String(i) + ":" + String(Encoder[i].read()));
  }
  
}
