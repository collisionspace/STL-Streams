//
// Created by James Slone on 11/20/16.
//

#ifndef SLONE_PROJECT3_LOGGER_H
#define SLONE_PROJECT3_LOGGER_H


#include <string>
#include <iostream>

using namespace std;

class Logger {

public:

    void log(const string);
    static Logger* getLogger();

private:
    Logger();
    Logger(const Logger&);
    static Logger *logger;
};



#endif //SLONE_PROJECT3_LOGGER_H
