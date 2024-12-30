#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include <vector>

// Функция перевода строки в обратную польскую запись
std::vector<std::string> InfixToPostfix(const std::string& expression);

// Функция вычисления выражения в формате обратной польской записи
double EvaluatePostfix(const std::vector<std::string>& postfix);

#endif // EXPRESSION_PARSER_H
