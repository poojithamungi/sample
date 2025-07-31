#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <algorithm>

/**
 * @brief Seat Adjustment System for Vehicle Infotainment HMI.
 */
class SeatAdjustmentSystem {
private:
    std::vector<std::string> seatPresets; ///< List of seat position presets.
    std::deque<std::string> eventQueue; ///< Queue for user input events.
    std::list<std::string> actionHistory; ///< History of seat adjustments.

public:
    /**
     * @brief Constructor - Initializes predefined seat position presets.
     */
    SeatAdjustmentSystem() {
        seatPresets = {
            "Position 1: Height 10cm, Lumbar 5",
            "Position 2: Height 12cm, Lumbar 3",
            "Position 3: Height 8cm, Lumbar 7"
        };
    }

    /**
     * @brief Add a new seat position preset.
     * @param preset Seat preset description.
     */
    void addSeatPreset(const std::string& preset) {
        seatPresets.push_back(preset);
    }

    /**
     * @brief Display all available seat presets.
     */
    void displaySeatPresets() const {
        std::cout << "Seat Position Presets:\n";
        for (const auto& preset : seatPresets) {
            std::cout << "- " << preset << "\n";
        }
    }

    /**
     * @brief Add a user input event to the queue.
     * @param event Input event description.
     * @param priority Set true if event is a priority event.
     */
    void addEvent(const std::string& event, bool priority = false) {
        if (priority) {
            eventQueue.push_front(event);
        } else {
            eventQueue.push_back(event);
        }
    }

    /**
     * @brief Process the next event in the queue (FIFO order).
     */
    void processEvent() {
        if (!eventQueue.empty()) {
            std::cout << "Processing Event: " << eventQueue.front() << "\n";
            eventQueue.pop_front();
        } else {
            std::cout << "No events to process.\n";
        }
    }

    /**
     * @brief Add an action to the history.
     * @param action Action description.
     */
    void addActionHistory(const std::string& action) {
        actionHistory.push_back(action);
    }

    /**
     * @brief Undo the last action in the history.
     */
    void undoLastAction() {
        if (!actionHistory.empty()) {
            std::cout << "Undoing Action: " << actionHistory.back() << "\n";
            actionHistory.pop_back();
        } else {
            std::cout << "No actions to undo.\n";
        }
    }

    /**
     * @brief Display all actions in history.
     */
    void displayHistory() const {
        std::cout << "Action History:\n";
        for (const auto& action : actionHistory) {
            std::cout << "- " << action << "\n";
        }
    }

    /**
     * @brief Display filtered actions by type.
     * @param filterType Action type prefix (e.g., "[Height]").
     */
    void displayFilteredHistory(const std::string& filterType) const {
        std::cout << "Filtered Action History (" << filterType << "):\n";
        for (const auto& action : actionHistory) {
            if (action.find(filterType) == 0) {
                std::cout << "- " << action << "\n";
            }
        }
    }
};

int main() {
    SeatAdjustmentSystem system;

    // Example Usage
    system.displaySeatPresets();
    system.addSeatPreset("Position 4: Height 15cm, Lumbar 6");
    system.displaySeatPresets();

    system.addEvent("AdjustHeight");
    system.addEvent("DriverChange", true);
    system.processEvent();
    system.processEvent();

    system.addActionHistory("[Height] Adjust Height 10cm");
    system.addActionHistory("[Lumbar] Adjust Lumbar 5");
    system.displayHistory();
    system.undoLastAction();
    system.displayFilteredHistory("[Height]");

    return 0;
}