#include "commandparsing.hpp"
#include <iostream>
#include <sstream>
#include <iomanip> // for std::quoted
#include <map>
#include <vector>
#include <algorithm> // for std::find

namespace commandparsing 
{
    std::vector<std::string> tokenize(const std::string &command)
    {
        std::vector<std::string> tokens;
        std::istringstream iss(command);
        std::string token;

        while (iss >> std::quoted(token)) {
            tokens.push_back(token);
        }

        return tokens;

    }

    commanderror check_command_syntax(const std::vector<command>& commands , const std::vector<std::string>& tokens)
    {
        // Error codes:
        // 0 = no error
        // 1 = too few arguments
        // 2 = unknown command

        // Must have at least one token to check the base command
        if (tokens.empty() || tokens[0] != "prayer")
        {
            return commanderror::unkown_command;
        }

        // Must have at least 2 tokens: "prayer <subcommand>"
        if (tokens.size() < 2)
        {
            return commanderror::too_few_arguments;
        }

        const std::string &subcommand = tokens[1];

        // Check if subcommand exists
        auto it = std::find_if(commands.begin(), commands.end(),
        [&](const command& cmd) {
            return cmd.name == subcommand;
        });
        if (it == commands.end())
        {
            return commanderror::unkown_command;
        }

        // Special case: "prayertimes" requires 4 tokens
        if (subcommand == "prayertimes" && tokens.size() != 4)
        {
            return commanderror::too_few_arguments;
        }

        // Special case: "para" requires 3 tokens
        if (subcommand == "para" && tokens.size() != 3)
        {
            return commanderror::too_few_arguments;
        }

        return commanderror::ok;
    }

    void print_error_messages(const std::vector<command> &commands, const std::vector<std::string>& tokens)
    {
        commanderror error = check_command_syntax(commands,tokens);
        if(error == commanderror::unkown_command)
        {
            std::cerr << "Unkown command." << std::endl;
            return;
        }
        else if(error == commanderror::too_few_arguments)
        {
            std::cout << "too few arguments." << std::endl;
            return;

        }
    }
}

