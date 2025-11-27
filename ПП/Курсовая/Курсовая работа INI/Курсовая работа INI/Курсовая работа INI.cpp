#include "INI_Parser.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        ini_parser parser("config.ini.txt");

        cout << "=== Тестирование парсера INI ===\n";
        int int_val = parser.get_value<int>("Section1.var1");
        double double_val = parser.get_value<double>("Section1.var2");
        string str_val = parser.get_value<string>("Section2.var2");

        cout << "Section1.var1 (int): " << int_val << endl;
        cout << "Section1.var2 (double): " << double_val << endl;
        cout << "Section2.var2 (string): " << str_val << endl;

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}
