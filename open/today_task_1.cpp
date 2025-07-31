#include <iostream>
#include <string>
#include <mutex>
#include <memory>
#include <thread>
#include <unordered_map>
using namespace std;

class HMIEventLogger {
private:
    std::string componentName;
    // static std::mutex logMutex;

    void log(const std::string& level, const std::string& message) {
        // std::lock_guard<std::mutex> lock(logMutex);
        std::cout << "[" << level << "] "
                  << "[" << componentName << "] "
                  << message << std::endl;
    }

public:
    HMIEventLogger(const std::string& name) : componentName(name) {}

    void Info(const std::string& msg) { log("INFO", msg); }
    void Warning(const std::string& msg) { log("WARNING", msg); }
    void Error(const std::string& msg) { log("ERROR", msg); }
};

// std::mutex HMIEventLogger::logMutex;

class HMIEventLoggerFactory {
public:
    static std::shared_ptr<HMIEventLogger> getLogger(const std::string& componentName) {
        return std::make_shared<HMIEventLogger>(componentName);
    }
};

// Simulated modules
void speedometerModule() {
    auto logger = HMIEventLoggerFactory::getLogger("Speedometer");
    logger->Info("Speed is within limits.");
    logger->Warning("Speed nearing upper limit.");
    logger->Error("Speed exceeded safe threshold!");
}

void fuelGaugeModule() {
    auto logger = HMIEventLoggerFactory::getLogger("FuelGauge");
    logger->Info("Fuel level optimal.");
    logger->Warning("Fuel level low.");
    logger->Error("Fuel exhausted!");
}

void checkEngineModule(){
    auto logger = HMIEventLoggerFactory::getLogger("CheckEngine");
    logger->Info("Engine function is normal.");
    logger->Warning("Engine is having high temperature.");
    logger->Error("Engine may have failed!");
}

void airbagWarningModule(){
    auto logger = HMIEventLoggerFactory::getLogger("AirbagWarning");
    logger->Info("Airbag is safe.");
    logger->Warning("Airbag is leaking.");
    logger->Error("Airbag is not found!");
}

// 🟩 Final main function
int main() {
    speedometerModule();
    fuelGaugeModule();
    checkEngineModule();
    airbagWarningModule();

    return 0;
}
