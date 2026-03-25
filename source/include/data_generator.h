#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H
#include <string>

std::string read_file(const std::string& file_path);
std::string generate_random_data(int length);

#endif