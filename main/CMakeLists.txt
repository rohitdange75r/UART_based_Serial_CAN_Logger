idf_component_register(SRCS "Serial_CAN_Logger.c"
                    INCLUDE_DIRS "."
                    REQUIRES bsp spi_driver mcp2515)
