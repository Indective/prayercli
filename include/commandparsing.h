#ifndef COMMANDPARSING_H
#define COMMANDPARSING_H

#include <vector>
#include <iostream>

class commandparsing
{
public:
    std::vector<std::string> tokenize(const std::string &command);
    int check_command_syntax(const std::map<std::string,std::string> commands,const std::string &command);
    void print_error_messages(const std::map<std::string,std::string> commands,const std::string &command);

};

#endif