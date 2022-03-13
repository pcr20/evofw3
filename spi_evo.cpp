#include "config.h"

#include "spi_evo.h"
#include <Arduino.h>
#include <SPI.h>


//CC1101 datasheet states max 6.5Mhz clock without faff, or 10MHz with some faff
// SPI_CLOCK_DIV4 would set it to 4Mhz
//SPI_MODE 0 (clock on rising edge)
//MSB_FIRST
//
// for HwCS, CS pin needs to be GPIO15  (pinSet is SPI_PINS_HSPI)
//
// on ESP32, the SPI object is instantiated in SPI.cpp as SPIClass SPI(VSPI);
// VSPI determines which SPI peripheral, and which pins - see esp32-hal-spi.h
// pins are defined in pins_arduino.h:
//static const uint8_t SS    = 5;
//static const uint8_t MOSI  = 23;
//static const uint8_t MISO  = 19;
//static const uint8_t SCK   = 18;


void spi_init(void) {
  SPI.begin(); //setup pin io (undone by .end())
  SPI.beginTransaction(SPISettings(6500000, MSBFIRST, SPI_MODE0)); //I assume SPI is a global object defined somewhere in Arduino.h
  SPI.setHwCs(true); //setup pin io
}

void spi_deassert(void) {
  //digitalWrite(chipSelectPin, HIGH);
  //should not be needed
  //__asm__ __volatile__ ("nop\n\t");
  __asm__ __volatile__ ("nop");
}

void spi_assert(void) {
  //digitalWrite(chipSelectPin, LOW);
  //should not be needed
  __asm__ __volatile__ ("nop");
}

uint8_t spi_check_miso(void) {
  //return ( SPI_PIN & (1 << SPI_MISO) );
  return ( digitalRead(MISO));
}

uint8_t spi_send(uint8_t data) {
  return SPI.transfer(data);
}

uint8_t spi_strobe(uint8_t b) {
    return spi_send(b);
}

