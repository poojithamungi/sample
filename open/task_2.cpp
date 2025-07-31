#include<iostream>
#include<algorithm>
#include<thread>
#include<mutex>
#include<string>
using namespace std;
/**
 * @brief it is an logger class used to represent the logger instance
 * in this class log function is dispaly the logname and respected message
 * @param log_name is  parameter one is used to dispaly the log
 * @param message is used to display the respected message of the log
 * in this class totally three funcions are created those are inf,warning,error to display the respaected log commands
 * mutex is used to synchronize the threads for effective resource allocation
 */
class HMIEventLogger{
    private:
    string componentname;
    // static mutex logmutex;
    // lock_guard<mutex> lock(logmutex);

    void log(const string& log_name,const string& message){
        cout<<"["<<log_name<<"]"<<"["<<componentname<<"]"<<message;

    }
    public:
    HMIEventLogger(const string&name):componentname(name){}
    void Info(const string& msg) {log("Info",msg);}
    void Warning(const string& msg){log("Warning",msg);}
    void Error(const string& msg){log("Error",msg);}
};
// HMIEventLogger::logmutex;
/**
 * in this line HMIEventLoggerFactory is an factory name it used to create an interface for creating object
 * getlogger is the method to check for which log-name or component create an object 
 */
class HMIEventLoggerFactory {
public:
    static std::shared_ptr<HMIEventLogger> getLogger(const std::string& componentName) {
        return std::make_shared<HMIEventLogger>(componentName);
    }
};
/**
 * @brief speedometermodule is used to check the speed controls of hmi
 * it is having the total three loggers like info,warning,error
 * @brief fuelengine will takecare of the messages of the fuel control
 * it is also having the three loggers like info,warning,error
 * @brief checkEngineModule is checking the functionality of engine
 * it is also having the three loggers meassges like info,warning,error
 * @brief airbagWarningModule will checks the functionality of the airbags
 * it is also having the three loggers messages like info,warning,error
 */
void speedometerModule() {
    auto logger = HMIEventLoggerFactory::getLogger("Speedometer");
    logger->Info("Speed should be limits.");
    logger->Warning("Speed reaching the upper limit");
    logger->Error("Speed exceeded safe");
}
void fuelEngineModule(){
    auto logger=HMIEventLoggerFactory::getLogger("FuelGuage");
    logger->Info("limited fuel is having");
    logger->Warning("fuel is near to empty");
    logger->Error("fuel is exceeded");
}
void checkEngineModule(){
    auto logger=HMIEventLoggerFactory::getLogger("CheckEngine");
    logger->Info("engine function is normal");
    logger->Warning("engine is having high temperature");
    logger->Error("engine may be failed!");
}
void airbagWarningModule(){
 auto logger=HMIEventLoggerFactory::getLogger("AirbagWarning");
 logger->Info("air bag is safe");
 logger->Warning("airbag is leaking");
 logger->Error("airbag is not found!");
}
// void displayThreads(){
//     lock_guard<mutex> HMIEventLogger::logmutex(const string& componentName);
//     cout<<"All Hmi logging completet";
// }
/**
 * @brief main method is used call the threads and displat the functionality
 * join is used to start the threads.
 */
int main(){
  
   
thread t1(displayThreads());
t1.join();
thread t2(speedometerModule());
t2.join();
thread t3(fuelEngineModule());
t1.join();
thread t4(checkEngineModule());
t2.join();
thread t5(airbagWarningModule());
t1.join();
 
}