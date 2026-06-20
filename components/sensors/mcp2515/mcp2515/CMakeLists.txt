idf_component_register(SRCS "mcp2515.c" "mcp2515_spi.c"
                       INCLUDE_DIRS "include"
                       PRIV_INCLUDE_DIRS "../private"
                       REQUIRES spi_driver)
