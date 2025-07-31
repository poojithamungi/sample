#include<iostream>
using namespace std;
class Singleton{
    private:
        Singleton();
        static Singleton* instancePtr;
        Singleton(const Singleton& obj) = delete;
        Singleton& operator = (const Singleton&) = delete;
        Singleton(Singleton&& obj) noexcept = delete;
    public:
        static Singleton* createInstance() {
            if(instancePtr == nullptr){
                instancePtr = new Singleton();
            }
            return instancePtr;
        }
        static Singleton* getInstance(){
            //static Singleton instance;
            return instancePtr;
        }
        void func() {
            cout << "Singleton working" << endl;
        }
};
Singleton* Singleton::instancePtr;
//Singleton::Singleton(){}
int main(){
    cout << "Main program started..." << endl;
    Singleton* s1 = Singleton::getInstance();
    s1->func();
    return 0;
}