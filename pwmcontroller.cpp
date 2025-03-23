#include "pwmcontroller.h"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>

PwmController::PwmController(int pwmChipNumber, int channel)
    : m_pwmChipNumber(pwmChipNumber), m_channel(channel) {
    // 构建 sysfs 路径（如 /sys/class/pwm/pwmchip2/pwm0）
    std::ostringstream oss;
    oss << "/sys/class/pwm/pwmchip" << m_pwmChipNumber
        << "/pwm" << m_channel;
    m_basePath = oss.str();
}

bool PwmController::initPwm() {
    // 导出 PWM 通道
    std::ostringstream exportPath;
    exportPath << "/sys/class/pwm/pwmchip" << m_pwmChipNumber << "/export";
    return writeSysFs(exportPath.str(), std::to_string(m_channel));
}

bool PwmController::setPeriod(unsigned int periodNs) {
    return writeSysFs(m_basePath + "/period", std::to_string(periodNs));
}

bool PwmController::setDutyCycle(unsigned int dutyNs) {
    return writeSysFs(m_basePath + "/duty_cycle", std::to_string(dutyNs));
}

bool PwmController::enable() {
    return writeSysFs(m_basePath + "/enable", "1");
}

bool PwmController::disable() {
    return writeSysFs(m_basePath + "/enable", "0");
}

bool PwmController::writeSysFs(const std::string& path, const std::string& value) {
    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }
    file << value;
    file.close();
    return true;
}
