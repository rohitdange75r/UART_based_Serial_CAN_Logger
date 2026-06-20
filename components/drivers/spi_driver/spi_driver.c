#include "spi_driver.h"
#include <string.h>

esp_err_t generic_spi_bus_init(spi_host_device_t host, int mosi_pin, int miso_pin, int sclk_pin)
{
    spi_bus_config_t bus_cfg = {
        .mosi_io_num = mosi_pin,
        .miso_io_num = miso_pin,
        .sclk_io_num = sclk_pin,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
    };
    esp_err_t ret = spi_bus_initialize(host, &bus_cfg, SPI_DMA_CH_AUTO);
    return (ret == ESP_ERR_INVALID_STATE) ? ESP_OK : ret;
}

esp_err_t generic_spi_add_device(spi_host_device_t host, int cs_pin, int clock_speed_hz, int spi_mode, spi_bus_device_handle_t *out_handle)
{
    spi_device_interface_config_t dev_cfg = {
        .clock_speed_hz = clock_speed_hz,
        .mode = spi_mode,
        .spics_io_num = cs_pin,
        .queue_size = 7,
    };
    return spi_bus_add_device(host, &dev_cfg, out_handle);
}

esp_err_t generic_spi_transfer(spi_bus_device_handle_t handle, const uint8_t *tx_data, uint8_t *rx_data, size_t length_bytes)
{
    if (!handle)
        return ESP_ERR_INVALID_ARG;
    spi_transaction_t transaction;
    memset(&transaction, 0, sizeof(spi_transaction_t));
    transaction.length = length_bytes * 8;
    transaction.tx_buffer = tx_data;
    transaction.rx_buffer = rx_data;
    return spi_device_transmit(handle, &transaction);
}