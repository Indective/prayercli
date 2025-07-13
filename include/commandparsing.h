#ifndef COMMANDPARSING_H
#define COMMANDPARSING_H

#include <vector>
#include <iostream>

class commandparsing
{
public:
    std::vector<std::string> tokenize(const std::string &command);

};

#endif