/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "driver/uart.h"

// UART1 配置（用于 LoRa）
#define LORA_UART_NUM      UART_NUM_1
#define LORA_UART_TX_PIN   17   
#define LORA_UART_RX_PIN   16   
#define LORA_UART_BAUD     9600
#define LORA_BUF_SIZE      1024

void app_main(void)
{
    printf("Hello world!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
   

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }

    // 配置 UART1 用于 LoRa 通信
    uart_config_t uart_config = {
        .baud_rate = LORA_UART_BAUD,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    uart_param_config(LORA_UART_NUM, &uart_config);
    uart_set_pin(LORA_UART_NUM, LORA_UART_TX_PIN, LORA_UART_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(LORA_UART_NUM, LORA_BUF_SIZE, 0, 0, NULL, 0);


    printf("  TX: GPIO%d\n", LORA_UART_TX_PIN);
    printf("  RX: GPIO%d\n", LORA_UART_RX_PIN);

    // 主循环：发送测试数据
    const char *data = "Hello LoRa!";
    int count = 0;

    while (1) {
        // 发送数据到 LoRa
        uart_write_bytes(LORA_UART_NUM, data, strlen(data));
        printf("[%d] Sent to LoRa: %s\n", count, data);

       
    }
}
