#include "cli_parser.h"
#include <iostream>
using namespace std;

Config getCommand(int argc, char* argv[]) {
    Config command;
    for (int i = 1 ; i < argc ; i++) {
        string agv = argv[i];
        if (agv == "-a" && i+1 < argc) {
            command.algorithm = argv[++i];
        }
        else if (agv == "-i" && i+1 < argc) {
            command.inputFile = argv[++i];
        }
        else if (agv == "-o" && i+1 < argc) {
            command.outputFile = argv[++i];
        }
    }
    command.errorMsg = "";
    if (command.algorithm == "") command.errorMsg += "Missing algorithm. ";
    if (command.inputFile == "") command.errorMsg += "Missing input file. "; 
    if (command.outputFile == "") command.errorMsg += "Missing output file. ";
    
    if (command.algorithm != "" && command.algorithm != "kmp" && command.algorithm != "rk" && command.algorithm != "bm" && command.algorithm != "bf") {
        command.errorMsg += "Invalid algorithm.";
    }
    
    if (command.errorMsg != "") {
        command.isValid = false;
    }

    

    return command;
}