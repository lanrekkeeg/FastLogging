#include<iostream>
#include<string>
#include "logging.cpp"
using namespace std;
/*
 DEBUG 10
 INFO 20
 WARN 30
 ERROR 40
*/


int main(){

logging log;
log.set_level("DEBUG");

log.debug("Hellow word",__LINE__,__SHORT_FILE__, __func__);
log.info("Hellow word",__LINE__,__SHORT_FILE__,__func__);
log.warn("Hellow word",__LINE__,__SHORT_FILE__, __func__);
log.error("out of bound Error at index:",__LINE__,__SHORT_FILE__, __func__);



}
