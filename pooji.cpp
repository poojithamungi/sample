#include<iostream>
#include<deque>
#include<list>
#include<string>
#include<vector>
using namespace std;
class SeatAdjustment{
 
    vector<string>seatpostion;
    deque<string>eventqueue;
    list<string>seatadjustment;
    public:
    SeatAdjustment (){
        seatposition={ "Position 1: Height 10cm, Lumbar 5",
            "Position 2: Height 12cm, Lumbar 3",
            "Position 3: Height 8cm, Lumbar 7"};
    }
    void addpreset(const string& st){
        seatposition.push_back(st);
    }
    void display(){
        cout<<"all available seats are:"<<endl;
        for(auto &i:seatposition){
           cout<<"-"<<i;
        }
        
    }
    


    }

}
int main(){cout<<"Position 1: Height 10cm, Lumbar 5"<<endl;

}
