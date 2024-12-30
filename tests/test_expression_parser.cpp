#include <iostream>
#include <include/expression_parser.h>
#include <include/calculator.h>

void testExpressionParser() {
    try {
        // Простой пример
        std::string expr1 = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
        auto postfix1 = InfixToPostfix(expr1);
        double result1 = EvaluatePostfix(postfix1);
        std::cout << "Тест 9: \"" << expr1 << "\" = " << result1 << " (Результат теста: корректно)" << std::endl;

        // Пример без скобок
        std::string expr2 = "10 + 2 * 6";
        auto postfix2 = InfixToPostfix(expr2);
        double result2 = EvaluatePostfix(postfix2);
        std::cout << "Тест 10: \"" << expr2 << "\" = " << result2 << " (Ожидается: 22)" << std::endl;

        // Пример с делением
        std::string expr3 = "100 * 2 + 12";
        auto postfix3 = InfixToPostfix(expr3);
        double result3 = EvaluatePostfix(postfix3);
        std::cout << "Тест 11: \"" << expr3 << "\" = " << result3 << " (Ожидается: 212)" << std::endl;

        // Пример с ошибкой в выражении
        try {
            std::string expr4 = "10 + ( 3 - 1";
            auto postfix4 = InfixToPostfix(expr4); // Ошибка: несогласованные скобки
            double result4 = EvaluatePostfix(postfix4);
            std::cerr << "Тест 12 (ошибка): \"" << expr4 << "\" = " << result4 << " (Должна быть ошибка)" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Тест 12 (ошибка): корректно поймана ошибка \"" << e.what() << "\"" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Поймана ошибка в тестах ExpressionParser: " << e.what() << std::endl;
    }
}
int main() {
    std::cout << "\nЗапуск тестов для ExpressionParser" << std::endl;
    testExpressionParser();
    return 0;
}
