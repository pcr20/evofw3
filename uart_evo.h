/***************************************************************
** uart.h
**
*/
#ifndef _UART_H_
#define _UART_H_
#ifdef __cplusplus
extern "C" {
#endif
void uart_rx_enable(void);
void uart_tx_enable(void);
void uart_disable(void);

void uart_init_evo(void);
void uart_work(void);
#ifdef __cplusplus
}
#endif
#define RADIO_BAUDRATE 38400

#endif // _UART_H_
