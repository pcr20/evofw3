#ifndef _SPI_H_
#define _SPI_H_

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
void spi_init(void);

void spi_deassert(void);
void spi_assert(void);
uint8_t spi_check_miso(void);

uint8_t spi_send(uint8_t data);
uint8_t spi_strobe(uint8_t b);
#ifdef __cplusplus
}
#endif

#endif
