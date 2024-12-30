#include "../include/expression_parser.h"
#include "../include/calculator.h"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <cctype>

namespace {

// Проверка, является ли символ оператором
bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == '&' || c == '|' || c == '_';
}

// Приоритеты операторов
int Precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Проверка ассоциативности (право ассоциативный оператор '^')
bool IsRightAssociative(char op) {
    return op == '^';
}

// Разделение строки на токены
std::vector<std::string> Tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::istringstream stream(expression);
    char c;

    while (stream >> c) {
        if (isdigit(c) || c == '.') { // Число
            stream.putback(c);
            double number;
            stream >> number;
            tokens.push_back(std::to_string(number));
        } else if (IsOperator(c) || c == '(' || c == ')') { // Оператор или скобка
            tokens.emplace_back(1, c);
        }
    }

    return tokens;
}

} // namespace

std::vector<std::string> InfixToPostfix(const std::string& expression) {
    std::vector<std::string> postfix;
    std::stack<char> operators;
    auto tokens = Tokenize(expression);

    for (const auto& token : tokens) {
        if (isdigit(token[0]) || token[0] == '.') { // Число
            postfix.push_back(token);
        } else if (token == "(") {
            operators.push('(');
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != '(') {
                postfix.emplace_back(1, operators.top());
                operators.pop();
            }
            if (operators.empty() || operators.top() != '(') {
                throw std::invalid_argument("Несогласованные скобки");
            }
            operators.pop();
        } else if (IsOperator(token[0])) { // Оператор
            while (!operators.empty() &&
                   Precedence(operators.top()) >= Precedence(token[0]) &&
                   !IsRightAssociative(token[0])) {
                postfix.emplace_back(1, operators.top());
                operators.pop();
            }
            operators.push(token[0]);
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(') {
            throw std::invalid_argument("Несогласованные скобки");
        }
        postfix.emplace_back(1, operators.top());
        operators.pop();
    }

    return postfix;
}

double EvaluatePostfix(const std::vector<std::string>& postfix) {
    std::stack<double> values;
    for (const auto& token : postfix) {
        if (isdigit(token[0]) || token[0] == '.') {
            values.push(std::stod(token));
        } else if (IsOperator(token[0])) {
            if (values.size() < 2) {
                if (token[0] == '_' || token[0] == '|' || token[0] == '-') {
                    double num1 = values.top(); values.pop();
                    values.push(Calculator::calculateUnary(num1, token[0]));
                }
                else {
                    throw std::invalid_argument("Некорректное выражение");
                }
            } else {
                double num2 = values.top(); values.pop();
                double num1 = values.top(); values.pop();
                values.push(Calculator::calculate(num1, num2, token[0]));
            }
        }
    }

    if (values.size() != 1) {
        throw std::invalid_argument("Некорректное выражение");
    }

    return values.top();
}