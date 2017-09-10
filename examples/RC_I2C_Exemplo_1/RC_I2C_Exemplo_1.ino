#include <Arduino.h>
#include <Tucotronics_RC_I2C.h>

Tucotronics_RC_I2C rele(0x20);
void setup() {
  
}

void loop() {
  for (int canal = 1; canal <= 8; canal++){
    rele.ligar(canal);
    delay(1000);
  }
  for (int canal = 1; canal <= 8; canal++){
    rele.desligar(canal);
    delay(1000);
  }

}
