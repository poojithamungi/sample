#include <iostream>
using namespace std;

// Segregated interfaces
class IPrinter {
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

// Concrete class: Printer only
class BasicPrinter : public IPrinter {
public:
    void print() override {
        cout << "Printing document..." << endl;
    }
};

// Concrete class: All-in-one machine
class MultiFunctionPrinter : public IPrinter, public IScanner {
public:
    void print() override {
        cout << "MultiFunctionPrinter printing..." << endl;
    }

    void scan() override {
        cout << "MultiFunctionPrinter scanning..." << endl;
    }
};

int main() {
    BasicPrinter bp;
    bp.print(); // Only prints

    MultiFunctionPrinter mfp;
    mfp.print(); // Prints and scans
    mfp.scan();

    return 0;
}
