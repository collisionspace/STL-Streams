//
// Created by James Slone on 11/20/16.
//
#include <fstream>
#include "Logger.h"

Logger* Logger::logger = NULL;
Logger::Logger(){}
Logger* Logger::getLogger() {
    if (logger == NULL)
        logger = new Logger();
    return logger;
}

void Logger::log(const string message) {
    std::ofstream outfile;

    outfile.open("/Users/slonej3/Documents/logfile.txt", std::ios_base::app);
    outfile << message << "\n";
}