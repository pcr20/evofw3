/**********************************************************
** esp_pins.h
**
** Abstract pin names and definitions for ESP8266
**
*/

#ifndef _CONFIG_H_
 #error "Include config.h instead of this file"
#endif

#ifndef _HW_ARDUINO_H_
#define _HW_ARDUINO_H_

#if defined(ESP8266) || defined(ESP32)
#define INT0 0
#define INT1 1
#define EIMSK 1
#define EIFR 1
#else
#include <avr/io.h>
#endif
// SPI port defs
#if defined(ESP8266)
#define SPI_SS      15
#define SPI_MOSI    13 //GPIO13 https://arduino-esp8266.readthedocs.io/en/latest/libraries.html?highlight=spi#spi
#define SPI_MISO    12 //GPIO12
#define SPI_SCLK    14 //GPIO14

// GDO0 connection - Serial input TX data to CC1101
  #define GDO0_PIN        4

// GDO2 connection - Serial output RX data from CC1101
  #define GDO2_PIN        5

#elif defined(ESP32)
//(see esp32-hal-spi.h)
// VSPI  3 //SPI bus normally attached to pins 5, 18, 19 and 23, but can be matrixed to any pins

//defined in pins_arduino.h
//static const uint8_t SS    = 5;
//static const uint8_t MOSI  = 23;
//static const uint8_t MISO  = 19;
//static const uint8_t SCK   = 18;

#define SPI_SS      5 //GPIO5
#define SPI_MOSI    23 //GPIO23
#define SPI_MISO    19 //GPIO19
#define SPI_SCLK    18 //GPIO18

#ifndef RX2
#define RX2 16 //GPIO16
#endif

#ifndef TX2
#define TX2 17 //GPIO17
#endif

// GDO0 connection - Serial input TX data to CC1101
  #define GDO0_PIN        17

// GDO2 connection - Serial output RX data from CC1101
  #define GDO2_PIN        16

#define HWUART
#undef SWUART

#define EX_UART_NUM UART_NUM_2

#else
#error wrong processor
#endif



// GDO0 interrupt
#if( GDO0==INT0 )
  #define GDO0_INT_MASK   ( 1 << INT0 )
  #define GDO0_INT_VECT   INT0_vect
  #define GDO0_INT_ISCn0  ( 1 << ISC00 )
  #define GDO0_INT_ISCn1  ( 1 << ISC01 )
#elif( GDO0==INT1 )
  #define GDO0_INT_MASK   ( 1 << INT1 )
  #define GDO0_INT_VECT   INT1_vect
  #define GDO0_INT_ISCn0  ( 1 << ISC10 )
  #define GDO0_INT_ISCn1  ( 1 << ISC11 )
#else
  #error "GDO0 not mapped"
#endif

// GDO2 interrupt
#if( GDO2==INT1 )
  #define GDO2_INT_MASK   ( 1 << INT1 )
  #define GDO2_INT_VECT   INT1_vect
  #define GDO2_INT_ISCn0  ( 1 << ISC10 )
  #define GDO2_INT_ISCn1  ( 1 << ISC11 )
#elif( GDO2==INT0 )
  #define GDO2_INT_MASK   ( 1 << INT0 )
  #define GDO2_INT_VECT   INT0_vect
  #define GDO2_INT_ISCn0  ( 1 << ISC00 )
  #define GDO2_INT_ISCn1  ( 1 << ISC01 )
#else
  #error "GDO2 not mapped"
#endif

#if defined(SWUART)
// Software interrupt
#define SW_INT_ENBL     ( 1<<PCIE0 )
#define SW_INT_VECT      PCINT0_vect
#define SW_INT_MASK      PCMSK0
#define SW_INT_PORT      PORTB
#define SW_INT_PIN       PINB
#define SW_INT_DDR       DDRB
#define SW_INT_IN        ( 1<<PORTB0 )
#endif // SWUART

// Some debug pins
#if !(defined(ESP8266) || defined(ESP32))
#define DEBUG_PORT        PORTC
#define DEBUG_DDR         DDRC
#define DEBUG_PIN1        ( 1<<PORTC0 )
#define DEBUG_PIN2        ( 1<<PORTC1 )
#define DEBUG_PIN3        ( 1<<PORTC2 )
#define DEBUG_PIN4        ( 1<<PORTC4 )
#define DEBUG_PIN5        ( 1<<PORTC5 )
#define DEBUG_PIN6        ( 1<<PORTC6 )
#endif

// TTY USB
#define TTY_USB
// LED
#define LED_DDR   DDRB
#define LED_PORT  PORTB
#define LED_PIN   5

#endif
