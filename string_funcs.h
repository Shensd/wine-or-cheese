#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include <string>
#include <vector>

std::vector<std::string> split(std::string, char delim);
std::string join(std::vector<std::string>, char paste);

#endif // !STRING_FUNCS_H
