#ifndef tucotronics_rc_I2Ch
#define tucotronics_rc_I2Ch

class Tucotronics_RC_I2C{
public:
    Tucotronics_RC_I2C(uint8_t endereco); 
    void ligar(uint8_t canal);
    void desligar(uint8_t canal);
    void desligarTudo();
private:
    uint8_t _endereco;
    uint8_t _data;
};
#endif
