/*
  Tucotronics_RC_Memo.cpp - Biblioteca para uso da placa de comando de relês RC-Memo com microcontroladores baseados no ESP8266.
  
*/


#include <Wire.h>

#include <Tucotronics_RC_I2C.h>

/**
* @brief Construtor para a placa RC7.
* @param pinA Número do pino da saída digital do ESP8266 (LSB).
* @param pinB Número do pino da saída digital do ESP8266.
* @param pinC Número do pino da saída digital do ESP8266 (MSB).
* @param pinLD Número do pino da saída digital do ESP8266 usado para ligar ou desligar os canais.
* @comment Pode-se usar os numeros definidos como D0, D1, D2, etc...
*/
Tucotronics_RC_I2C::Tucotronics_RC_I2C(uint8_t endereco){
    _data = 0;
    _endereco = endereco;
    Wire.begin();    
}


/**
* @brief Desliga todos os canais.
* @comment Pode-se usar este metodo no setup() para evitar canais ligados quando a placa é energizada.
*/
void Tucotronics_RC_I2C::desligarTudo(){
    Wire.beginTransmission(_endereco);
    _data = 0;
    Wire.write(_data);
    Wire.endTransmission();
}

/**
* @brief Liga um canal.
* @param canal Numero do canal para ligar.
*/
void Tucotronics_RC_I2C::ligar(uint8_t canal){
    
    Wire.beginTransmission(_endereco);
    _data |= (1 << (canal-1));
    Wire.write(_data);
    Wire.endTransmission();
}

/**
* @brief Desliga um canal.
* @param canal Numero do canal para desligar.
*/
void Tucotronics_RC_I2C::desligar(uint8_t canal){
    
    Wire.beginTransmission(_endereco);
    _data &= ~(1 << (canal-1));
    Wire.write(_data);
    Wire.endTransmission();
}
