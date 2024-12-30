#include <iostream>
#include <include/expression_parser.h>
#include <include/calculator.h>

void testCalculator() {
    try {
        std::cout << "Тест 1 (2 + 3): " << Calculator::calculate(2, 3, '+') << " (Ожидается: 5)" << std::endl;
        std::cout << "Тест 2 (5 - 3): " << Calculator::calculate(5, 3, '-') << " (Ожидается: 2)" << std::endl;
        std::cout << "Тест 3 (4 * 3): " << Calculator::calculate(4, 3, '*') << " (Ожидается: 12)" << std::endl;
        std::cout << "Тест 4 (10 / 2): " << Calculator::calculate(10, 2, '/') << " (Ожидается: 5)" << std::endl;
        std::cout << "Тест 5 (10 % 3): " << Calculator::calculate(10, 3, '%') << " (Ожидается: 1)" << std::endl;
        std::cout << "Тест 6 (2 ^ 3): " << Calculator::calculate(2, 3, '^') << " (Ожидается: 8)" << std::endl;

        // Унарные операции
        std::cout << "Тест 7 (_16): " << Calculator::calculateUnary(16, '_') << " (Ожидается: 4)" << std::endl;
        std::cout << "Тест 8 (|(-5)): " << Calculator::calculateUnary(-5, '|') << " (Ожидается: 5)" << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Поймана ошибка в тестах Calculator: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Запуск тестов для Calculator" << std::endl;
    testCalculator();
    return 0;
}
