#pragma once

#include <vector>
#include <iostream>
#include <map>

enum class commanderror
{
    ok = 0,
    too_few_arguments = 1,
    unkown_command = 2
};

struct command
{
    std::string name;
    std::string description;

};
namespace commandparsing
{
    std::vector<std::string> tokenize(const std::string &command);
    commanderror check_command_syntax(const std::vector<command>& commands , const std::vector<std::string>& tokens);
    void print_error_messages(const std::vector<command>& commands,const std::vector<std::string>& tokens);
};
