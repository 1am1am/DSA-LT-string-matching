#ifndef CLI_PARSER_H
#define CLI_PARSER_H
#include <vector>
#include <string>

struct Config {
    std::string algorithm;
    
    std::vector<std::string> pattern;
    std::string input_file;
    
    bool is_valid = true;
    bool show_positions = false;
    bool mode_comparison = false;

    std::string error_msg;
};

#endif