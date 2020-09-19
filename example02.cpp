#include<iostream>
#include "logging.cpp"
using namespace std;

void hell_world2(logging &log){
    log.debug("Inside",__LINE__,__SHORT_FILE__, __func__);
    log.info("Hello world",__LINE__,__SHORT_FILE__, __func__);
    if (1)
      log.debug("Inside if check",__LINE__,__SHORT_FILE__, __func__);
}

void hell_world1(logging &log){
    //cout<<"Hellow World"<<endl;
    log.info("Hello world",__LINE__,__SHORT_FILE__, __func__);
}
int main(){
    logging log;
    log.set_level("DEBUG");
    //cout<<"Hello World!"<<endl;
    log.info("Hello world",__LINE__,__SHORT_FILE__, __func__);
    hell_world1(log);
    hell_world2(log);
}