#ifndef PWMCONTROLLER_H
#define PWMCONTROLLER_H

#include <string>

class PwmController {
public:
    // 构造函数：指定 PWM 控制器编号（如 pwmchip2）和通道号
    PwmController(int pwmChipNumber = 2, int channel = 0);

    // 初始化 PWM（导出通道）
    bool initPwm();

    // 设置周期（单位：纳秒）
    bool setPeriod(unsigned int periodNs);

    // 设置占空比（单位：纳秒）
    bool setDutyCycle(unsigned int dutyNs);

    // 启用 PWM 输出
    bool enable();

    // 关闭 PWM 输出
    bool disable();

private:
    int m_pwmChipNumber;  // PWM 控制器编号（如 17）
    int m_channel;        // 通道号（如 0）
    std::string m_basePath;  // sysfs 基础路径（如 /sys/class/pwm/pwmchip17/pwm0）

    // 写入 sysfs 文件
    bool writeSysFs(const std::string& path, const std::string& value);
};

#endif // PWMCONTROLLER_H
