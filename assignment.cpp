#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <functional> // For std::greater

/**
 * @class HMITelltaleSystem
 * @brief A system to manage and display automotive telltale warnings and notifications.
 */
class HMITelltaleSystem {
public:
    /** 
     * @brief Unique active telltales currently active.
     * Prevents duplicates.
     */
    std::set<std::string> activeTelltales;

    /**
     * @brief Frequency tracker for all activations (includes duplicates).
     */
    std::multiset<std::string> telltaleHistory;

    /**
     * @brief Stores last activation timestamp (string) for each telltale.
     */
    std::map<std::string, std::string> lastActivationTime;

    /**
     * @brief Category mapping: category -> multiple telltales.
     */
    std::multimap<std::string, std::string> categoryMap;

    /**
     * @brief FIFO queue for telltale notifications (activation/deactivation messages).
     */
    std::queue<std::string> notificationQueue;

    /**
     * @brief Stack to track last resolved (deactivated) telltales for recovery or undo.
     */
    std::stack<std::string> recoveryStack;

    /**
     * @brief Priority queue for emergency telltales.
     * Lower int = higher priority.
     */
    std::priority_queue<
        std::pair<int, std::string>, 
        std::vector<std::pair<int, std::string>>, 
        std::greater<std::pair<int, std::string>>
    > emergencyQueue;

    /**
     * @brief Add a mapping from telltale to category (for setup).
     * @param telltale Name of the telltale warning.
     * @param category Functional category of the telltale.
     */
    void addCategoryMapping(const std::string& telltale, const std::string& category) {
        categoryMap.insert(std::make_pair(category, telltale));
    }

    /**
     * @brief Activate a telltale warning.
     * Adds to active set, logs activation, updates timestamp, queues notification.
     * @param telltale Name of the telltale to activate.
     * @param timestamp Activation time string (e.g., "10:32:15").
     */
    void activateTelltale(const std::string& telltale, const std::string& timestamp) {
        activeTelltales.insert(telltale);
        telltaleHistory.insert(telltale);
        lastActivationTime[telltale] = timestamp;
        notificationQueue.push(telltale + " Activated");
    }

    /**
     * @brief Deactivate a telltale warning.
     * Removes from active set, logs recovery, queues notification.
     * @param telltale Name of the telltale to deactivate.
     */
    void deactivateTelltale(const std::string& telltale) {
        activeTelltales.erase(telltale);
        recoveryStack.push(telltale);
        notificationQueue.push(telltale + " Deactivated");
    }

    /**
     * @brief Clear all active telltales (e.g., on ignition off).
     */
    void ignitionOff() {
        activeTelltales.clear();
        // Optional: could also clear notificationQueue or other states
    }

    /**
     * @brief Display all currently active telltales.
     */
    void displayActiveTelltales() const {
        std::cout << "Active Telltales:\n";
        for (std::set<std::string>::const_iterator it = activeTelltales.begin(); it != activeTelltales.end(); ++it) {
            std::cout << "- " << *it << "\n";
        }
    }

    /**
     * @brief Show frequency (count) and positions of activations of a telltale.
     * @param telltale Name of the telltale to query.
     */
    void showFrequency(const std::string& telltale) const {
        int count = telltaleHistory.count(telltale);
        std::cout << telltale << " activated " << count << " times.\n";

        std::pair<std::multiset<std::string>::const_iterator, std::multiset<std::string>::const_iterator> range = telltaleHistory.equal_range(telltale);
        std::cout << "Occurrences at positions: ";
        for (std::multiset<std::string>::const_iterator it = range.first; it != range.second; ++it) {
            std::cout << std::distance(telltaleHistory.begin(), it) << " ";
        }
        std::cout << "\n";
    }

    /**
     * @brief Display last activation timestamps for all telltales.
     */
    void displayLastActivationTimes() const {
        std::cout << "Last activation timestamps:\n";
        for (std::map<std::string, std::string>::const_iterator it = lastActivationTime.begin(); it != lastActivationTime.end(); ++it) {
            std::cout << it->first << " : " << it->second << "\n";
        }
    }

    /**
     * @brief Display all telltales belonging to a specific category.
     * @param category The category name to filter by.
     */
    void displayCategoryTelltales(const std::string& category) const {
        std::cout << "Telltales in category '" << category << "':\n";
        std::pair<std::multimap<std::string, std::string>::const_iterator, std::multimap<std::string, std::string>::const_iterator> range = categoryMap.equal_range(category);
        for (std::multimap<std::string, std::string>::const_iterator it = range.first; it != range.second; ++it) {
            std::cout << "- " << it->second << "\n";
        }
    }

    /**
     * @brief Process and display all notifications in FIFO order.
     * Clears the notification queue.
     */
    void processNotifications() {
        std::cout << "Processing notifications:\n";
        while (!notificationQueue.empty()) {
            std::cout << notificationQueue.front() << "\n";
            notificationQueue.pop();
        }
    }

    /**
     * @brief Review recovery history stack (LIFO).
     */
    void reviewRecoveryHistory() const {
        std::cout << "Recovery history:\n";
        std::stack<std::string> temp = recoveryStack; // Copy to avoid modifying original
        while (!temp.empty()) {
            std::cout << "- " << temp.top() << "\n";
            temp.pop();
        }
    }

    /**
     * @brief Push a critical emergency telltale with priority.
     * @param priority Integer priority (lower = more critical).
     * @param telltale Name of the emergency telltale.
     */
    void pushEmergency(int priority, const std::string& telltale) {
        emergencyQueue.push(std::make_pair(priority, telltale));
    }

    /**
     * @brief Handle emergency telltales by priority.
     * Displays and removes all emergencies from the queue.
     */
    void handleEmergency() {
        std::cout << "Handling emergencies:\n";
        while (!emergencyQueue.empty()) {
            std::pair<int, std::string> top = emergencyQueue.top();
            std::cout << "Priority " << top.first << ": " << top.second << "\n";
            emergencyQueue.pop();
        }
    }
};

// Example usage:
int main() {
    HMITelltaleSystem hmi;

    // Setup categories
    hmi.addCategoryMapping("ABS", "Brake System");
    hmi.addCategoryMapping("Brake Failure", "Brake System");
    hmi.addCategoryMapping("Airbag", "Safety");
    hmi.addCategoryMapping("Low Fuel", "Engine");
    hmi.addCategoryMapping("Oil Pressure", "Engine");
    hmi.addCategoryMapping("Seatbelt", "Safety");

    // Activate some telltales
    hmi.activateTelltale("ABS", "10:00:01");
    hmi.activateTelltale("Airbag", "10:01:15");
    hmi.activateTelltale("Low Fuel", "10:05:23");
    hmi.activateTelltale("ABS", "10:10:45"); // re-activated

    hmi.displayActiveTelltales();

    hmi.showFrequency("ABS");

    hmi.displayLastActivationTimes();

    hmi.displayCategoryTelltales("Safety");

    hmi.deactivateTelltale("Airbag");
    hmi.deactivateTelltale("Low Fuel");

    hmi.reviewRecoveryHistory();

    hmi.processNotifications();

    // Emergency warnings
    hmi.pushEmergency(1, "Brake Failure");
    hmi.pushEmergency(3, "Airbag");
    hmi.pushEmergency(2, "Oil Pressure");
    hmi.handleEmergency();

    // Clear on ignition off
    hmi.ignitionOff();
    hmi.displayActiveTelltales();

    return 0;
}
