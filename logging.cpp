#include<iostream>
#include<string>
#include<fstream>
#include <chrono> 
#include <ctime> 
#include <algorithm>
#include "util.h"
using namespace std;

class logging {
    private:
        // set the logging leve
        string level;
        // set the output type either console or file
        string stream;
        // set the file path incase of output to file
        string file_path;
        // open the file for writing 
        ofstream file_out;
        // logging priority
        //int logging_level[4];
        int curr_Loglevel;

    public:
    // override constructor for initialization the logging
    logging(){
        this->curr_Loglevel = 10;
        //cout<<curr_Loglevel;
        //this->level =   level;
        //set_logging_priority(priority, 4, level);
    }

    void set_level(string level){
        if (level == "DEBUG")
            curr_Loglevel = _DEBUG;
        else if (level == "INFO")
            curr_Loglevel = _INFO;
        else if (level == "WARN")
            curr_Loglevel = _WARN;
        else if (level == "ERROR")
            curr_Loglevel = _ERROR;
        //else curr_Loglevel = 10;
    }

    void set_logging_priority(bool *pri, int size, string _level){

        for (int i=0; i<size; i++)
            cout<<pri[i];
    }
    // setting console output
    void set_output_to_console(){
        stream = "console";
        cout<<"Stream set to console";
    }

    //Pending
    // setting the output to the file
    void set_output_to_file(string path){
        //ofstream out;
        file_out.open("log.txt");
        if (file_out.is_open()){
            stream = "file";
            cout<<"Stream set to file ["<<path<<"]";
            cout<<"File is loaded sucessfully";
        }
        else cout<<"Fail to load the file,there is some issue with path.Setting log level to console";
    }

    // Preparing message to log
    string prepare_message(string str){
        return "nothing";
    }
    // Retrieve the latest date/time
    string get_current_timeDate(){
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string curr_time = ctime(&timenow);
        curr_time.erase(std::remove(curr_time.begin(), curr_time.end(), '\n'), curr_time.end());
        return curr_time;
    }

    void debug(string msg, int line, string file, string func, string str="null"){
        // Debug log
        if (_DEBUG >= curr_Loglevel)
            LOGDEBUG(msg,line, file, func);
            
    }

    void warn(string msg, int line, string file, string func, string str="null"){
        // Debug log
        if (_WARN >= curr_Loglevel)
            LOGWARN(msg, line, file, func);
    }

    void error(string msg, int line, string file, string func, string str="null"){
        // Debug log
        if (_ERROR >= curr_Loglevel)
            LOGERROR(msg, line, file, func);
    }

    void info(string msg, int line, string file, string func, string str="null"){
        // Debug log
        if (_INFO >= curr_Loglevel)
            LOGINFO(msg, line, file, func);
    }

};
