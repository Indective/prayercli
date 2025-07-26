#pragma once

#include <vector>
#include <iostream>
#include <map>

enum class CommandError
{
    OK = 0,
    TOO_FEW_ARGUMENTS = 1,
    UNKOWN_COMMAND = 2
};

namespace commandparsing
{
    std::vector<std::string> tokenize(const std::string &command);
    CommandError check_command_syntax(const std::map<std::string, std::string>& commands , const std::vector<std::string> tokens);
    void print_error_messages(const std::map<std::string,std::string>& commands,const std::vector<std::string> tokens);
};
