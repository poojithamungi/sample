#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing Square" << endl;
    }
};

void render(const Shape& s) {
    s.draw();
}
int main(){
    Circle c;
    Square r;
    // Shape s;
    render(c);
    render(r);
}
