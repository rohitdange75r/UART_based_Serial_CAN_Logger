#include "mcp2515.h"
#include "mcp2515_priv.h"
#include "mcp2515_cmd.h"

void mcp2515_reset(void)
{
    uint8_t cmd = MCP2515_CMD_RESET;
    generic_spi_transfer(internal_spi_handle, &cmd, NULL, 1);
}

uint8_t mcp2515_read_register(uint8_t reg_addr)
{
    uint8_t tx[3] = {MCP2515_CMD_READ, reg_addr, 0x00};
    uint8_t rx[3] = {0};
    generic_spi_transfer(internal_spi_handle, tx, rx, 3);
    return rx[2];
}

