#include<iostream>
#include<memory>
using namespace std;
class Animal{
    public:
    void eat(){
        cout<<"animal is eating"<<endl;
    }
};
int main(){
 shared_ptr<Animal>obj1=make_unique<Animal>();
 shared_ptr<Animal>obj2=obj1;
 obj2->eat();
 cout<<"ptr count"<<obj1.use_count()<<endl;
 if(obj1==obj2){
    cout<<"both are sharing same memory"<<endl;
 }
 else{
    cout<<"no";
 }
 
 return 0;
}