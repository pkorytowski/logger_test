#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>


#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON




int main(){

    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("example_log_file.txt");

    spdlog::logger logger("example",{console_sink, file_sink});



    for(int i=0;i<20;i++) {
        
        if (i==5){
            console_sink->set_level(spdlog::level::trace);
            file_sink->set_level(spdlog::level::debug);
            logger.info("log levels changed. console:trace, file:debug In {} loop iteration", i);
        }

        if (i==7){
            console_sink->set_level(spdlog::level::trace);
            file_sink->set_level(spdlog::level::err);
            logger.info("log levels changed. console:trace, file:err (it should be not visible in file) In {} loop iteration", i);
        }

        if (i==15){
            console_sink->set_level(spdlog::level::warn);
            file_sink->set_level(spdlog::level::trace);
            logger.info("log levels changed. console:err, file:trace (it should be not visible in console) In {} loop iteration", i);
        }


       
        logger.info("This is info message {} iteration",i);
        logger.warn("This is warn message {} iteration", i);
        logger.error("This is error message {} iteration", i);
        logger.critical("This is critical message {} iteration", i);
        std::cout<<std::endl<<std::endl;
        
        
        
    }

 


}