#include <iostream>
#include <vector>
#include<list>
#include<deque>

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
