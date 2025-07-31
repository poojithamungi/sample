#include <iostream>
using namespace std;

// Step 1: Base class
class Animal {
public:
    virtual void speak() = 0;  // Pure virtual function
    virtual ~Animal() {}       // Virtual destructor
};

// Step 2: Derived classes
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog says: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat says: Meow!" << endl;
    }
};

// Step 3: Factory class
class AnimalFactory {
public:
    static Animal* createAnimal(const string& type) {
        if (type == "dog") return new Dog();
        else if (type == "cat") return new Cat();
        else return nullptr;
    }
};

// Step 4: Main function
int main() {
    Animal* animal1 = AnimalFactory::createAnimal("dog");
    Animal* animal2 = AnimalFactory::createAnimal("cat");

    if (animal1) animal1->speak();  // Dog says: Woof!
    if (animal2) animal2->speak();  // Cat says: Meow!

    // Clean up
    delete animal1;
    delete animal2;

    return 0;
}
