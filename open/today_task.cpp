// #include <iostream>
// #include <string>
// #include <vector>

// // ---- SRP: User Data Handling ----
// class User {
//     std::string name;
//     std::string email;
//     std::string phone;
//     std::string whatsappNumber;
// public:
//     User(std::string n, std::string e, std::string p, std::string w)
//         : name(n), email(e), phone(p), whatsappNumber(w) {}
//     std::string getName() const { return name; }
//     std::string getEmail() const { return email; }
//     std::string getPhone() const { return phone; }
//     std::string getWhatsAppNumber() const { return whatsappNumber; }
// };

// // ---- SRP & ISP: Notification Interfaces ----
// // Base Notification Interface: minimal methods
// class INotification {
// public:
//     virtual void send(const User& user, const std::string& message) = 0;
//     virtual ~INotification() = default;
// };

// // ---- SRP: Logging ----
// class Logger {
// public:
//     void log(const std::string& message) {
//         std::cout << "[LOG]: " << message << std::endl;
//     }
// };

// // ---- Concrete Notification Implementations ----
// class EmailNotification : public INotification {
// public:
//     void send(const User& user, const std::string& message) override {
//         std::cout << "Sending Email to " << user.getEmail()
//                   << ": " << message << std::endl;
//     }
// };

// class SMSNotification : public INotification {
// public:
//     void send(const User& user, const std::string& message) override {
//         std::cout << "Sending SMS to " << user.getPhone()
//                   << ": " << message << std::endl;
//     }
// };

// class WhatsAppNotification : public INotification {
// public:
//     void send(const User& user, const std::string& message) override {
//         std::cout << "Sending WhatsApp message to " << user.getWhatsAppNumber()
//                   << ": " << message << std::endl;
//     }
// };

// // ---- DIP: Notification Manager depends on abstraction ----
// class NotificationManager {
//     std::vector<INotification*> notifiers;
//     Logger logger;
// public:
//     // Register a notifier (caller manages notifier lifetime)
//     void registerNotifier(INotification* notifier) {
//         notifiers.push_back(notifier);
//     }

//     void notifyAll(const User& user, const std::string& message) {
//         for (auto& notifier : notifiers) {
//             notifier->send(user, message);
//             logger.log("Notification sent.");
//         }
//     }
// };

// int main() {
//     User user("Alice", "alice@example.com", "123-456-7890", "alice_wa");

//     NotificationManager manager;

//     // Create concrete notifiers manually
//     EmailNotification* emailNotifier = new EmailNotification();
//     SMSNotification* smsNotifier = new SMSNotification();
//     WhatsAppNotification* waNotifier = new WhatsAppNotification();

//     // Register them
//     manager.registerNotifier(emailNotifier);
//     manager.registerNotifier(smsNotifier);
//     manager.registerNotifier(waNotifier);

//     std::string message = "Hello Alice! This is your notification.";
//     manager.notifyAll(user, message);

//     // Clean up manually to avoid memory leaks
//     delete emailNotifier;
//     delete smsNotifier;
//     delete waNotifier;

//     return 0;
// }
#include <iostream>
#include <string>

class VehicleConfigManager {
private:
    // Private static instance
    static VehicleConfigManager* instance;

    // Configuration settings
    std::string language;
    std::string units;
    std::string theme;

    // Private constructor
    VehicleConfigManager() : language("English"), units("Metric"), theme("Light") {}

    // Prevent copy constructor and assignment
    VehicleConfigManager(const VehicleConfigManager&) = delete;
    VehicleConfigManager& operator=(const VehicleConfigManager&) = delete;

public:
    // Static method to access the singleton instance
    static VehicleConfigManager* getInstance() {
        if (instance == nullptr) {
            instance = new VehicleConfigManager();
        }
        return instance;
    }

    // Setters
    void setLanguage(const std::string& lang) {
        language = lang;
    }

    void setUnits(const std::string& unitType) {
        units = unitType;
    }

    void setTheme(const std::string& thm) {
        theme = thm;
    }

    // Getters
    std::string getLanguage() const {
        return language;
    }

    std::string getUnits() const {
        return units;
    }

    std::string getTheme() const {
        return theme;
    }

    // For demo
    void printConfig() const {
        std::cout << "Language: " << language
                  << ", Units: " << units
                  << ", Theme: " << theme << std::endl;
    }
};

// Initialize static member
VehicleConfigManager* VehicleConfigManager::instance = nullptr;

// Example usage
int main() {
    // Part 1 of system
    VehicleConfigManager* config1 = VehicleConfigManager::getInstance();
    config1->setLanguage("French");
    config1->setUnits("Imperial");
    config1->setTheme("Dark");

    std::cout << "[System Component A] Configuration:\n";
    config1->printConfig();

    // Part 2 of system
    VehicleConfigManager* config2 = VehicleConfigManager::getInstance();
    std::cout << "\n[System Component B] Configuration (after changes):\n";
    config2->printConfig();

    // Confirm same instance
    std::cout << "\nSame instance? " << (config1 == config2 ? "Yes" : "No") << std::endl;

    return 0;
}
