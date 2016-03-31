#ifndef EEPROM_UTILS_H
#define EEPROM_UTILS_H

#include <Arduino.h>

class EEPROMUtils {
public:
	static void write(int address, int value);
	static int readInt(int address);
};

#endif
