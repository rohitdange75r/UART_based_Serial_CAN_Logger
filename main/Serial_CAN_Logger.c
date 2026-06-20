#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "bsp_board.h"
#include "spi_driver.h"
#include "mcp2515.h"

static const char *TAG = "MAIN_APP";

void app_main(void)
{
    spi_bus_device_handle_t spi_module = NULL;

    // 1. Initialize physical bus hardware lines
    if (generic_spi_bus_init(SPI3_HOST, BOARD_PIN_MOSI, BOARD_PIN_MISO, BOARD_PIN_SCLK) != ESP_OK)
    {
        ESP_LOGE(TAG, "Fatal error on physical bus layer config!");
        return;
    }

    // 2. Attach slave protocol structure requirements
    if (generic_spi_add_device(SPI3_HOST, BOARD_PIN_CS, 10000000, 0, &spi_module) != ESP_OK)
    {
        ESP_LOGE(TAG, "Fatal error attaching device instance handle!");
        return;
    }

    if (mcp2515_init(spi_module, BOARD_PIN_INT) != ESP_OK)
    {
        ESP_LOGE(TAG, "Fatal error initializing MCP2515 module!");
        return;
    }
    else
    {
        ESP_LOGI(TAG, "MCP2515 module initialized successfully!");
    }
}