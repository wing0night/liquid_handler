#include "gpiocontroller.h"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/stat.h>

GpioController::GpioController(int gpio_index)
    : m_gpio_index(gpio_index) {
    // 构建 sysfs 路径（如 /sys/class/gpio/gpio150）
    std::ostringstream oss;
    oss << "/sys/class/gpio/gpio" << m_gpio_index;
    m_basePath = oss.str();
}

bool GpioController::initGpio() {
    // 导出 gpio 通道
    std::ostringstream exportPath;
    exportPath << "/sys/class/gpio/export";
    return writeSysFs(exportPath.str(), std::to_string(m_gpio_index));
}

bool GpioController::setDir(std::string dir) {
    return writeSysFs(m_basePath + "/direction", dir);
}

bool GpioController::SetHigh() {
    return writeSysFs(m_basePath + "/value", "1");
}

bool GpioController::SetLow() {
    return writeSysFs(m_basePath + "/value", "0");
}

bool GpioController::writeSysFs(const std::string& path, const std::string& value) {
    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }
    file << value;
    file.close();
    return true;
}
