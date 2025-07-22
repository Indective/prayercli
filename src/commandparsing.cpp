#include "commandparsing.h"
#include <iostream>
#include <sstream>
#include <iomanip> // for std::quoted
#include <map>
#include <vector>

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

CommandError commandparsing::check_command_syntax(const std::map<std::string, std::string> &commands , const std::vector<std::string> tokens)
{
    // Error codes:
    // 0 = no error
    // 1 = too few arguments
    // 2 = unknown command

    // Must have at least one token to check the base command
    if (tokens.empty() || tokens[0] != "prayer")
    {
        return CommandError::UNKOWN_COMMAND;
    }

    // Must have at least 2 tokens: "prayer <subcommand>"
    if (tokens.size() < 2)
    {
        return CommandError::TOO_FEW_ARGUMENTS;
    }

    const std::string &subcommand = tokens[1];

    // Check if subcommand exists
    if (commands.find(subcommand) == commands.end())
    {
        return CommandError::UNKOWN_COMMAND;
    }

    // Special case: "prayertimes" requires at least 4 tokens
    if (subcommand == "prayertimes" && tokens.size() < 4)
    {
        return CommandError::TOO_FEW_ARGUMENTS;
    }

    return CommandError::OK;
}

void commandparsing::print_error_messages(const std::map<std::string, std::string> &commands, const std::vector<std::string> tokens)
{
    CommandError error = check_command_syntax(commands,tokens);
    if(error == CommandError::UNKOWN_COMMAND)
    {
        std::cerr << "Unkown command." << std::endl;
        return;
    }
    else if(error == CommandError::TOO_FEW_ARGUMENTS)
    {
        std::cout << "too few arguments." << std::endl;
        return;

    }
}
