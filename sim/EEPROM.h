#ifndef EEPROM_SIM
#define EEPROM_SIM

class Eeprom{
	public:
	void write(int, int){}
	void update(int, int){}
};

extern Eeprom EEPROM;

#endif //EEPROM_SIM
