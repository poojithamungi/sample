#include <iostream>
using namespace std;

// Base class
class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying" << endl;
    }
    virtual ~Bird() = default;
};

// Derived class
class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow is flying swiftly" << endl;
    }
};

// Function that accepts base class
void makeBirdFly(Bird* bird) {
    bird->fly();  // Should work correctly for any subclass
}

int main() {
    Bird* b = new Bird();
    Sparrow* s = new Sparrow();

    cout << "Using Bird object:\n";
    makeBirdFly(b);

    cout << "\nUsing Sparrow object:\n";
    makeBirdFly(s);  // ✅ Valid: no need to change makeBirdFly()

    delete b;
    delete s;

    return 0;
}
