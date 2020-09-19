#include<iostream>
#include<string>
#include "logging.cpp"
using namespace std;


void cal_power(int num, int exp, logging &log){
    log.debug("Inside the function", __LINE__,__SHORT_FILE__, __func__);
    log.debug("num1 is:"+ to_string(num) + " exp is:"+ to_string(exp), __LINE__,__SHORT_FILE__, __func__ );


    int power = 1;
    for (int i=0; i<exp; i++){
        power *= num;
        log.debug(to_string(i+1)+ " Power is "+ to_string(power), __LINE__,__SHORT_FILE__, __func__);
    }
    log.info("Result is "+to_string(power), __LINE__, __SHORT_FILE__, __func__);
}

int main(){
logging log;
log.set_level("DEBUG");
cal_power(10,30,log);    //cout<<"hellow world";
}