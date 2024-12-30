#include <iostream>
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
        std::string a = "1111111111111111111111111111111111";
        std::cout << "Тест 9 (1111111111111111111111111111111111 + 1111111111111111111111111111111111): "
        << Calculator::LongSum(a, a) << " (Ожидается: 2222222222222222222222222222222222)" << std::endl;
        a = "999999999999999999999999999999999999999999999";
        std::string b = "999999999999999999999999999999999999999999999";
        std::cout << "Тест 9 (1111111111111111111111111111111111 + 1111111111111111111111111111111111111111111): "
        << Calculator::LongSum(a, b) << " (Ожидается: 1001111111111111111111111111111111111111111110)" << std::endl;
        std::cout << "Тест 10 (делители числа 20935093): "; Calculator::Factorize(20935093); std::cout << " (Ожидается: 19 1 151 1 7297 1)" << std::endl;
        std::cout << "Тест 11 (делители числа 214990848): "; Calculator::Factorize(214990848); std::cout << " (Ожидается: 2 15 3 8)" << std::endl;
        std::cout << "Тест 12 (корни выражения x^2 + 4x + 4): "; Calculator::SolveQuadratic(1, 4, 4); std::cout << " (Ожидается: Один корень -2)" << std::endl;
        std::cout << "Тест 13 (корни выражения x^2 + 4x + 5): "; Calculator::SolveQuadratic(1, 4, 5); std::cout << " (Ожидается: Нет корней)" << std::endl;
        std::cout << "Тест 14 (корни выражения 0): "; Calculator::SolveQuadratic(0, 0, 0); std::cout << " (Ожидается: Бесконечно много корней)" << std::endl;
        std::cout << "Тест 15 (корни выражения x^2 - 5x + 6): "; Calculator::SolveQuadratic(1, -5, 6); std::cout << " (Ожидается: Два корня 2 3)" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Поймана ошибка в тестах Calculator: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Запуск тестов для Calculator" << std::endl;
    testCalculator();
    return 0;
}
