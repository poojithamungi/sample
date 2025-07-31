#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car engine starting with ignition key..." << endl;
    }
    void stop() override {
        cout << "Car engine stopping..." << endl;
    }
};

class ElectricCar : public Vehicle {
public:
    void start() override {
        cout << "Electric car starting silently..." << endl;
    }
    void stop() override {
        cout << "Electric car stopping..." << endl;
    }
};

class VehicleOperator {
public:
    void operateVehicle(Vehicle* v) {
        v->start();
        // Imagine we add more operations that rely on correct behavior
        v->stop();
    }
};

int main() {
    Vehicle* car = new Car();
    Vehicle* electricCar = new ElectricCar();

    VehicleOperator operator1;

    cout << "Operating Car:" << endl;
    operator1.operateVehicle(car);

    cout << "\nOperating Electric Car:" << endl;
    operator1.operateVehicle(electricCar);

    delete car;
    delete electricCar;

    return 0;
}
