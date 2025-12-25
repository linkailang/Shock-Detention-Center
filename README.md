# 方案介绍

## esp-32 and lora（Long Range Radio） UART0通信

```text
 [L33-443 LoRa 模组]  ←UART0→  [e-Paper ESP32 DriverBoard]
                                  ↑
                               ESP32
```
## why?

```
当然是手上只有这些
```

### 服务器

![image-20251224223210077](https://gitee.com/tu-liangxiang/pic-img/raw/master/blog/image-20251224223210077.png)

==试试这个作为服务器还是本地待定。这个其实接触也不多==

### 引脚图

![alt text](assets/image.png)

> 

> **lora注意事项**
> 不过我们好像是L33 433UD22s 可以看看
> ![alt text](assets/image.png)



# 目前进度

- 上电配置环境，全忘记了，esp32不能跑stm32的hal库都不知道

- | 特性     | ESP32                 | STM32               |
  | -------- | --------------------- | ------------------- |
  | 架构     | Xtensa (32位)         | ARM Cortex-M        |
  | 开发环境 | Arduino IDE / ESP-IDF | STM32CubeIDE / Keil |
  | 代码格式 | `.ino` / `.cpp`       | `.c` (HAL库)        |
  | HAL库    | Arduino.h 或 ESP-IDF  | STM32 HAL           |

- 开启我的hello word!

- 连接uart0 不知道会不会和原始的调试输出搞混，但是我找不到！uart1

  - [安装驱动程序](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/peripherals/uart.html#uart-api-driver-installation) - 为 UART 驱动程序分配 ESP32 资源
  - [设置通信参数](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/peripherals/uart.html#uart-api-setting-communication-parameters) - 设置波特率、数据位、停止位等
  - [设置通信管脚](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/peripherals/uart.html#uart-api-setting-communication-pins) - 分配连接设备的管脚
  - [运行 UART 通信](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/peripherals/uart.html#uart-api-running-uart-communication) - 发送/接收数据
  - [使用中断](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/peripherals/uart.html#uart-api-using-interrupts) - 触发特定通信事件的中断
  - [删除驱动程序](https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-reference/peripherals/uart.html#uart-api-deleting-driver) - 如无需 UART 通信，则释放已分配的资源
  
- ## L33-433UD22S 工作模式必须靠 M0 / M1 决定

  | M1   | M0   | 模式         | 说明           |
  | ---- | ---- | ------------ | -------------- |
  | 0    | 0    | **透传模式** | 才能直接发数据 |
  | 0    | 1    | 配置模式     | AT 指令        |
  | 1    | 0    | WOR          | 低功耗         |
  | 1    | 1    | 休眠         | 不通信         |

#  问题点

 [问题点.md](doc/问题点.md) 
