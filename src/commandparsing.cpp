#include "commandparsing.h"
#include <iostream>
#include <sstream>
#include <iomanip> // for std::quoted

std::vector<std::string> commandparsing::tokenize(const std::string &command)
{
    std::vector<std::string> tokens;
    std::istringstream iss(command);
    std::string token;

    while (iss >> std::quoted(token)) {
        tokens.push_back(token);
    }

    return tokens;
}
