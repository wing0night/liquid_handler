#ifndef GPIOCONTROLLER_H
#define GPIOCONTROLLER_H

#include <string>

class GpioController {
public:
    // 构造函数：指定 PWM 控制器编号（如 pwmchip2）和通道号
    GpioController(int gpio_index = 150);

    // 初始化 gpio（导出通道）
    bool initGpio();

    bool setDir(std::string dir);
    bool SetHigh();
    bool SetLow();


private:
    int m_gpio_index;        // GPIO4_C6, 4*32+22
    std::string m_basePath;  // sysfs 基础路径（如 /sys/class/gpio/gpio150）

    // 写入 sysfs 文件
    bool writeSysFs(const std::string& path, const std::string& value);
};

#endif // GPIOCONTROLLER_H
