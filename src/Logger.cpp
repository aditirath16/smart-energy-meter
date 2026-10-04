#include "Logger.h"

#include <fstream>

void Logger::log(const std::string& message) {

    std::ofstream file(
        "logs/meter.log",
        std::ios::app
    );

    if (file.is_open()) {
        file << message << "\n";
        file.close();
    }
}