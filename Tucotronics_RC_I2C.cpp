/*
  Tucotronics_RC.cpp - Biblioteca para uso da placa de comando de relês RC com protocolo I2C.
  
*/
#include <Wire.h>
#include <Tucotronics_RC_I2C.h>

/**
* @brief Construtor.
* @param endereco Endereço da placa RC.
* @comment O endereço padrão com todos os dip switches em OFF é 0x20.
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
