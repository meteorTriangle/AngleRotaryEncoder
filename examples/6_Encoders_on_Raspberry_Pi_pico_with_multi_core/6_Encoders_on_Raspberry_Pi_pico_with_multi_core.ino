//only runs on Raspberry Pi pico
#include <rotaryEncoder.h>

rotaryEncoder Encoder[6];

void setup() {
  int j = 2;
  for(int i = 0; i<6; i++){
    Encoder[i].setPhase(j+(i*2), j+(i*2)+1);
    Encoder[i].init();
    Encoder[i].startCounter();
  }
}

void loop() {
  for(int i = 0; i<10; i++){
    Encoder[i].run();
  }
}

void setup1(){
  Serial.begin(115200);
}

void loop1(){
  for(int i = 0; i<6; i++){
    Serial.println("Encoder" + String(i) + ":" + String(Encoder[i].read()));
  }
  delay(100);
}
