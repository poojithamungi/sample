#include<iostream>
#include<string>
using namespace std;
class ConfigureManager{
    private:
    static ConfigureManager* instance;
    string language;
    string units;
    string theme;
    ConfigureManager():language("english"),units("metrics"),theme("light"){}
    ConfigureManager(const ConfigureManager&)=delete;
    ConfigureManager& operator=(const ConfigureManager&)=delete;
    public:
    static ConfigureManager* getInstance(){
        if(instance==nullptr){
            instance =new ConfigureManager();
        }
        return instance;
    }
    void setlanguagemethod(const string& lang){
        language=lang;
    }
    void setunitmethod(const string& unit){
        units=unit;
    }
    void setthememethod(const string& them){
        theme=them;
    }
    string getlanguage() const{
        return language;
    }
    string getunits() const{
        return units;
    }
    string gettheme()const{
        return theme;
    }
    void printdemo()const{
        cout<<"language:"<<language<<endl;
        cout<<"units:"<<units<<endl;
        cout<<"theme:"<<theme<<" ";
    }
};
ConfigureManager* ConfigureManager::instance=nullptr;
int main(){
    ConfigureManager* config1=ConfigureManager::getInstance();
    config1->getlanguage();
    config1->getunits();
    config1->gettheme();
    cout<<"before";
     cout<<endl;
    config1->printdemo();
    ConfigureManager* config2=ConfigureManager::getInstance();
    config2->setlanguagemethod("french");
    config2->setunitmethod("metrics");
    config2->setthememethod("dark");
    cout<<endl;
    cout<<"after";
    cout<<endl;
    config2->printdemo();
    cout<<((config1==config2)?"both are pointing to the same memory":"pointing to different memories");
    
    
}
// #include<iostream>
// using namespace std;
// class Singleton{
//     private:
//     static Singleton* instance;
//     Singleton(){};
//     Singleton(const Singleton&)=delete;
//     Singleton& operator=(const Singleton&)=delete;
//     public:
//     static Singleton* createInstance(){
//         if(instance==nullptr){
//             return new Singleton;
//         }
//         return instance;
//     }
//     static Singleton* getInstance(){
//         // static Singleton instance;
//         return instance;
//     }
//     void func(){
//         cout<<"hello world";
//     }
// };
// Singleton*  Singleton::instance=nullptr;
// int main()
// {
//     Singleton* s1= Singleton::getInstance();
//     s1->func();
    
// }