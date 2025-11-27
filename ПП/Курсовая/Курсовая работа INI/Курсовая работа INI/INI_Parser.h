#ifndef INI_PARSER_H
#define INI_PARSER_H
using namespace std;

#include <string> 
#include <unordered_map>

class ini_parser {
private:
    unordered_map< string, unordered_map< string, string>> sections;
    string trim(const string& str);

public:
    explicit ini_parser(const string& filename); 
    template<typename T>
    T get_value(const string& section_dot_key);
};

#endif 
