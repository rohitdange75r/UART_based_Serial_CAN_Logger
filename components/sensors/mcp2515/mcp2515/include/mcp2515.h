#ifndef MCP2515_H
#define MCP2515_H

#include "spi_driver.h"
#include "esp_err.h"

esp_err_t mcp2515_init(spi_bus_device_handle_t spi_link, int interrupt_pin);
void mcp2515_reset(void);
uint8_t mcp2515_read_register(uint8_t reg_addr);
void mcp2515_write_register(uint8_t reg_addr, uint8_t value);
void mcp2515_bit_modify(uint8_t reg_addr, uint8_t mask, uint8_t value);

#endif