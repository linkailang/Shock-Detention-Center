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

- UART接线，少带俩根线，明天再上电吧！
- esp32 有示例程序看了一眼，基于\#include <Arduino.h> 这个确实不太会，不过用起来挺简单的，不需要stm32 单独下载hal库，当然我还没用

