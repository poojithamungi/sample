#include <iostream>
#include <vector>

struct SeatPreset {
    std::string name;
    int height;
    int lumbar;
};

class SeatManager {
    std::vector<SeatPreset> presets;

public:
    void initializePresets() {
        presets.push_back({"Position 1", 10, 5});
        presets.push_back({"Position 2", 12, 3});
        presets.push_back({"Position 3", 8, 7});
    }

    void addPreset(const std::string& name, int height, int lumbar) {
        presets.push_back({name, height, lumbar});
    }

    void displayPresets() const {
        for (const auto& preset : presets)
            std::cout << preset.name << ": Height " << preset.height << "cm, Lumbar " << preset.lumbar << "\n";
    }
};
#include <iostream>
#include <deque>

class EventQueue {
    std::deque<std::string> queue;

public:
    void addEvent(const std::string& event, bool priority = false) {
        if (priority)
            queue.push_front(event);
        else
            queue.push_back(event);
    }

    void processEvent() {
        if (!queue.empty()) {
            std::cout << "Processing event: " << queue.front() << "\n";
            queue.pop_front();
        }
    }

    void displayQueue() const {
        std::cout << "Event Queue:\n";
        for (const auto& event : queue)
            std::cout << event << "\n";
    }
};
#include <iostream>
#include <list>

class SeatHistory {
    std::list<std::string> history;

public:
    void addAction(const std::string& action) {
        history.push_back(action);
    }

    void undoLastAction() {
        if (!history.empty()) {
            history.pop_back();
        }
    }

    void displayHistory(const std::string& filter = "") const {
        std::cout << "Seat Adjustment History:\n";
        for (const auto& action : history) {
            if (filter.empty() || action.find(filter) != std::string::npos) {
                std::cout << action << "\n";
            }
        }
    }
};
int main(){
 SeatManager s;
 EventQueue e;
 SeatHistory se;
}