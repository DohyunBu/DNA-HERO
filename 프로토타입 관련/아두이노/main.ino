#include <SMELib.h>

Bluetooth bluetooth(2,3);
Buzzer buzzer(13);
RGBLed rgb(9,10,11);

void setup() {
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()){
    char text = bluetooth.read();
    if(text == 'a'){
      rgb.setColor(0,255,0);
    }else if(text=='b'){
      rgb.setColor(255,0,0);
      buzzer.note('C',200);
    }
  }
}
