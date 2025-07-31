#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>  // For std::pair

using namespace std;

/**
 * @brief Demonstrate Unique Active Telltales using std::set
 * Prevent duplicates, insert new, erase, and clear on ignition off.
 * 
 * @param ignition Ignition status (true = on, false = off)
 */
void uniqueActiveTelltalesDemo(bool ignition) {
    set<string> Unique_Active_Telltales = {"ABS", "Airbag", "Low Fuel"};

    if (ignition) {
        Unique_Active_Telltales.insert("engine fuel");
        Unique_Active_Telltales.insert("engine pressure");
        Unique_Active_Telltales.insert("ABS");      // duplicate ignored
        Unique_Active_Telltales.insert("Low Fuel"); // duplicate ignored

        cout << "Active telltales are:\n";
        for (const auto& telltale : Unique_Active_Telltales) {
            cout << telltale << "\n";
        }
    } else {
        Unique_Active_Telltales.clear();
        cout << "Ignition off: All telltales cleared\n";
    }
}

/**
 * @brief Track every telltale activation using std::multiset
 * Allow duplicates to log frequency.
 */
void telltaleFrequencyTrackerDemo() {
    multiset<string> Telltale_Frequency;

    // Simulate activations
    Telltale_Frequency.insert("ABS");
    Telltale_Frequency.insert("ABS");
    Telltale_Frequency.insert("Airbag");
    Telltale_Frequency.insert("Low Fuel");
    Telltale_Frequency.insert("Airbag");

    cout << "Telltale activation history:\n";
    for (const auto& t : Telltale_Frequency) {
        cout << t << "\n";
    }

    string query = "ABS";
    cout << "Count of '" << query << "': " << Telltale_Frequency.count(query) << "\n";

    auto range = Telltale_Frequency.equal_range(query);
    cout << "Occurrences of '" << query << "':\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << "\n";
    }
}

/**
 * @brief Map each telltale to last activation timestamp using std::map
 * Update timestamp on re-activation.
 */
void telltaleTimestampMappingDemo() {
    map<string, string> Telltale_Timestamps;

    // Simulate activations with timestamps
    Telltale_Timestamps["ABS"] = "10:00:00";
    Telltale_Timestamps["Airbag"] = "10:01:05";
    Telltale_Timestamps["Low Fuel"] = "10:03:30";

    // Re-activation updates timestamp
    Telltale_Timestamps["ABS"] = "10:05:00";

    cout << "Telltale to timestamp mappings:\n";
    for (const auto& [telltale, timestamp] : Telltale_Timestamps) {
        cout << telltale << " -> " << timestamp << "\n";
    }
}

/**
 * @brief Map telltales to categories using std::multimap
 * Show all telltales for a specific category.
 */
void telltaleCategoryMappingDemo() {
    multimap<string, string> Category_Telltale;

    // Insert category -> telltale mappings
    Category_Telltale.insert({"Brake System", "ABS"});
    Category_Telltale.insert({"Safety", "Airbag"});
    Category_Telltale.insert({"Engine", "Engine Fuel"});
    Category_Telltale.insert({"Safety", "Seatbelt"});
    Category_Telltale.insert({"Engine", "Engine Pressure"});

    cout << "All categorized warnings:\n";
    for (const auto& [category, telltale] : Category_Telltale) {
        cout << category << " : " << telltale << "\n";
    }

    // Show telltales belonging to "Safety"
    string queryCategory = "Safety";
    cout << "\nTelltales in category '" << queryCategory << "':\n";
    auto range = Category_Telltale.equal_range(queryCategory);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << "\n";
    }
}

/**
 * @brief Queue telltale notifications using std::queue
 * FIFO for sequential notifications.
 */
void telltaleNotificationQueueDemo() {
    queue<string> NotificationQueue;

    // Push new notifications
    NotificationQueue.push("ABS Activated");
    NotificationQueue.push("Airbag Activated");
    NotificationQueue.push("Low Fuel Warning");

    cout << "Processing notifications:\n";
    while (!NotificationQueue.empty()) {
        cout << NotificationQueue.front() << "\n";
        NotificationQueue.pop();
    }
}

/**
 * @brief Track last resolved telltales using std::stack
 * LIFO for recovery history.
 */
void telltaleRecoveryHistoryDemo() {
    stack<string> RecoveryStack;

    // Push deactivated telltales
    RecoveryStack.push("Low Fuel");
    RecoveryStack.push("Airbag");
    RecoveryStack.push("ABS");

    cout << "Recovery history (last deactivated first):\n";
    while (!RecoveryStack.empty()) {
        cout << RecoveryStack.top() << "\n";
        RecoveryStack.pop();
    }
}

/**
 * @brief Handle critical warnings with priority queue
 * Lower int = higher priority
 */
void emergencyTelltaleQueueDemo() {
    // priority_queue by default is max heap, so invert priority by storing negative priority
    priority_queue<pair<int, string>> EmergencyQueue;

    // Insert critical warnings: priority, telltale
    EmergencyQueue.push({-1, "Brake Failure"});
    EmergencyQueue.push({-3, "Engine Fire"});
    EmergencyQueue.push({-2, "Airbag Failure"});

    cout << "Handling emergency warnings in priority order:\n";
    while (!EmergencyQueue.empty()) {
        // Replace structured binding with explicit pair extraction for compatibility
        auto p = EmergencyQueue.top();
        EmergencyQueue.pop();
        int priority = p.first;
        string warning = p.second;
        cout << warning << " (priority " << -priority << ")\n";
    }
}

int main() {
    cout << "--- Unique Active Telltales Demo ---\n";
    uniqueActiveTelltalesDemo(true);
    cout << "\n";

    cout << "--- Telltale Frequency Tracker Demo ---\n";
    telltaleFrequencyTrackerDemo();
    cout << "\n";

    cout << "--- Telltale Timestamp Mapping Demo ---\n";
    telltaleTimestampMappingDemo();
    cout << "\n";

    cout << "--- Telltale Category Mapping Demo ---\n";
    telltaleCategoryMappingDemo();
    cout << "\n";

    cout << "--- Telltale Notification Queue Demo ---\n";
    telltaleNotificationQueueDemo();
    cout << "\n";

    cout << "--- Telltale Recovery History Demo ---\n";
    telltaleRecoveryHistoryDemo();
    cout << "\n";

    cout << "--- Emergency Telltale Queue Demo ---\n";
    emergencyTelltaleQueueDemo();
    cout << "\n";

    return 0;
}
