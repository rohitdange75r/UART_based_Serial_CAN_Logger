#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "driver/spi_master.h"
#include "esp_err.h"

typedef spi_device_handle_t spi_bus_device_handle_t;

esp_err_t generic_spi_bus_init(spi_host_device_t host, int mosi_pin, int miso_pin, int sclk_pin);
esp_err_t generic_spi_add_device(spi_host_device_t host, int cs_pin, int clock_speed_hz, int spi_mode, spi_bus_device_handle_t *out_handle);
esp_err_t generic_spi_transfer(spi_bus_device_handle_t handle, const uint8_t *tx_data, uint8_t *rx_data, size_t length_bytes);

#endif