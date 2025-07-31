#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DrivingMode{
    public:
    virtual void activateMode()=0;
    virtual ~DrivingMode()=default;
};
class EcoMode:public DrivingMode{
    public:
    void activateMode()override{
        cout<<"this is ecomode"<<endl;
    }
};
class SportMode:public DrivingMode{
    void activateMode()override{
        cout<<"this is a sportmode"<<endl;
    }
};
class ComfortMode:public DrivingMode{
    void activateMode()override{
        cout<<"this is an comfortmode"<<endl;
    }
};
enum class ModeType{
    Eco,Sport,Comfort
};
class VehicleFactory{
    public:
    static DrivingMode* createDrivingMOde(ModeType mode) {
        switch (mode) {
            case ModeType::Eco: return new EcoMode();
            case ModeType::Sport: return new SportMode();
            case ModeType::Comfort: return new ComfortMode();
            default: return nullptr;
        }
    }
};
int main(){
    DrivingMode* model1=VehicleFactory::createDrivingMOde(ModeType::Eco);
    DrivingMode* model2=VehicleFactory::createDrivingMOde(ModeType::Sport);
    DrivingMode* model3=VehicleFactory::createDrivingMOde(ModeType::Comfort);
    model1->activateMode();
    model2->activateMode();
    model3->activateMode();
    delete model1;
    delete model2;
    delete model3;
    return 0;

}