
//#include "logging.cpp"
// Remove path from filename
#define __SHORT_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// Main log macro
#define __LOG__(format, loglevel, line,file,func,...) cout<<logging::get_current_timeDate()<<" ["<<loglevel<<"]"<<" ["<<func<<"] "<<"["<<file<<":"<<line<<"] "<<format<<endl

// Specific log macros with 
#define LOGDEBUG(msg, line,file ,func,...) __LOG__(msg, "DEBUG",line,file,func, ## __VA_ARGS__)
#define LOGWARN(msg, line,file,func,...) __LOG__(msg, "WARN",line,file,func, ## __VA_ARGS__)
#define LOGERROR(msg, line,file,func,...) __LOG__(msg, "ERROR", line,file,func,## __VA_ARGS__)
#define LOGINFO(msg, line,file,func,...) __LOG__(msg, "INFO", line,file,func,## __VA_ARGS__)
#define _DEBUG 10
#define _INFO 20
#define _WARN 30
#define _ERROR 40