#include<iostream>
#include<string>
using namespace std;
class User{
    private:
    string username;
    public:
    User(const string& username):username(username){};
    string getname()const {return username;}
};
class Display{
    public:
    void save(const User& user){
        cout<<"the username is:"<<user.getname()<<endl;
    }
};
class SecondMethod{
    public:
    void email(const User& user,const string message){
        cout<<message<<" "<<user.getname()<<endl;
    }
};
int main(){
    User u("poojitha");
    Display d;
    d.save(u);
    SecondMethod s;
    s.email(u,"hello good morning");
    return 0;
}