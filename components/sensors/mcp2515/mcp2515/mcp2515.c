#include "mcp2515.h"
#include "mcp2515_priv.h"

spi_bus_device_handle_t internal_spi_handle = NULL;
int internal_interrupt_pin = -1;

esp_err_t mcp2515_init(spi_bus_device_handle_t spi_link, int interrupt_pin)
{

    if (spi_link == NULL)
        return ESP_ERR_INVALID_ARG;
    internal_spi_handle = spi_link;
    internal_interrupt_pin = interrupt_pin;

    mcp2515_reset();
    return ESP_OK;
}