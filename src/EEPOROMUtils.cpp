#include <Arduino.h>
#include <EEPROM.h>

#include "EEPROMUtils.h"

int EEPROMUtils::readInt(int address) {
	byte one = EEPROM.read(address);
	byte two = EEPROM.read(address + 1);
	return (one << 8) + two;
}

void EEPROMUtils::write(int address, int value) {
	if (address >= EEPROM.length()) {
		Serial.println("Trying to write outside of EEPROM");
	}
	byte two = value & 0xFF;
	byte one = (value >> 8) & 0xFF;

	EEPROM.write(address, one);
	EEPROM.write(address + 1, two);
}
