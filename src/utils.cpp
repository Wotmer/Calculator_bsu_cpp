#include <include/utils.h>
#include <algorithm>
#include <cctype>

void trim(std::string& str) {
    // Удаляем пробелы в начале строки
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    // Удаляем пробелы в конце строки
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}
