#include "commandparsing.h"
#include <iostream>
#include <sstream>
#include <iomanip> // for std::quoted
#include <map>

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

int commandparsing::check_command_syntax(const std::map<std::string, std::string> commands , const std::string &command)
{
    // 0 : no error
    // 1 : too few arguments
    // 2 : unkown command
    
    std::vector<std::string> tokens = tokenize(command);

    if(tokens[0] != "prayer")
    {
        return 2;
    }
    if(tokens[1] == "prayertimes" && tokens.size() < 4)
    {
        return 1;
    }
    for(auto i : commands)
    {
        if(i.first == tokens[0]) // all commands do not take any arguments except "prayertimes"
        {
            return 0;
        }
    }
    return 2;
}

void commandparsing::print_error_messages(const std::map<std::string, std::string> commands, const std::string &command)
{
    int error = check_command_syntax(commands,command);
    if(error == 2)
    {
        std::cerr << "Unkown command." << std::endl;
        return;
    }
    else if(error == 1)
    {
        std::cout << "too few arguments." << std::endl;
        return;
    }
}
