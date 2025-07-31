#include <iostream>
#include <string>
using namespace std;

// Abstraction
class ILogger {
public:
    virtual void log(const string& message) = 0;
    virtual ~ILogger() = default;
};

// Low-level module
class ConsoleLogger : public ILogger {
public:
    void log(const string& message) override {
        cout << "Log: " << message << endl;
    }
};

// High-level module depends on abstraction (not concrete ConsoleLogger)
class ReportManager {
    ILogger* logger;
public:
    ReportManager(ILogger* log) : logger(log) {}

    void generateReport() {
        // Some logic...
        logger->log("Report generated successfully.");
    }
};

int main() {
    ConsoleLogger logger;
    ReportManager manager(&logger);
    manager.generateReport();

    return 0;
}
