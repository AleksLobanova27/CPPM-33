#include "INI_Parser.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cctype>
using namespace std;

string ini_parser::trim(const string& str) {
    string result = str;
    result.erase(result.begin(), find_if(result.begin(), result.end(),
        [](unsigned char ch) { return ! isspace(ch); }));
    result.erase( find_if(result.rend(), result.rend(),
        [](unsigned char ch) { return ! isspace(ch); }).base(), result.end());
    return result;
}

ini_parser::ini_parser(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Не удается открыть файл: " + filename);
    }

    string line;
    string current_section;

    while (getline(file, line)) {
        string trimmed = trim(line);
        if (trimmed.empty() || trimmed[0] == ';') continue;

        if (trimmed[0] == '[') {
            size_t end_pos = trimmed.find(']');
            if (end_pos != string::npos) {
                current_section = trim(trimmed.substr(1, end_pos - 1));
                sections[current_section];
            }
            continue;
        }

        size_t eq_pos = trimmed.find('=');
        if (eq_pos != string::npos) {
            string key = trim(trimmed.substr(0, eq_pos));
            string value = trim(trimmed.substr(eq_pos + 1));
            if (!key.empty() && !current_section.empty()) {
                sections[current_section][key] = value;
            }
        }
    }

    if (sections.empty()) {
        throw runtime_error("Файл INI пуст или некорректен");
    }
}

template<typename T>
T ini_parser::get_value(const string& section_dot_key) {
    size_t dot_pos = section_dot_key.find('.');
    if (dot_pos == string::npos) {
        throw runtime_error("Неверный формат: ожидается section.key");
    }

    string section = section_dot_key.substr(0, dot_pos);
    string key = section_dot_key.substr(dot_pos + 1);

    auto sec_it = sections.find(section);
    if (sec_it == sections.end()) {
        throw runtime_error("Секция '" + section + "' не найдена");
    }

    auto key_it = sec_it->second.find(key);
    if (key_it == sec_it->second.end()) {
        throw sruntime_error("Ключ '" + key + "' не найден в секции '" + section + "'");
    }

    try {
        if constexpr (is_same_v<T, int>) {
            return stoi(key_it->second);
        }
        else if constexpr (is_same_v<T, double>) {
            return stod(key_it->second);
        }
        else if constexpr (is_same_v<T, string>) {
            return key_it->second;
        }
        else {
            throw runtime_error("Неподдерживаемый тип");
        }
    }
    catch (const exception&) {
        throw runtime_error("Невозможно преобразовать '" + key_it->second + "' в тип " +
            typeid(T).name());
    }
}


template int ini_parser::get_value<int>(const string&);
template double ini_parser::get_value<double>(const string&);
template string ini_parser::get_value<string>(const string&);
