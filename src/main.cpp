#include <iostream>
#include <string>
#include <include/calculator.h>
#include "../include/expression_parser.h"
#include "include/utils.h"

void PrintMenu() {
    std::cout << "===== Калькулятор =====" << std::endl;
    std::cout << "1. Ввести выражение" << std::endl;
    std::cout << "2. Показать операции" << std::endl;
    std::cout << "3. Выйти" << std::endl;
    std::cout << "Выберите действие: ";
}

void PrintHelp() {
    std::cout << "1) Блок простых операций:" << std::endl;
    std::cout << "a + b (сумма а и b)" << std::endl;
    std::cout << "a - b (разность a и b)" << std::endl;
    std::cout << "a * b (произведение a и b)" << std::endl;
    std::cout << "a / b (деление a на b)" << std::endl;
    std::cout << "a ^ b (возведение a в степень b)" << std::endl;
    std::cout << "a % b (деление a с остатком b)" << std::endl;
    std::cout << "a & b (целочисленное деление a на b)" << std::endl;
    std::cout << "|a (модуль числа)" << std::endl;
    std::cout << "_a (корень из числа a)" << std::endl;
    std::cout << "2) Блок сложных операций:" << std::endl;
    std::cout << "1. Перемножение матриц (вводятся размеры матрицы, затем первая матрица построчно, далее вторая аналогично)" << std::endl;
    std::cout << "2. Нахождение делителей числа (вводится само число)" << std::endl;
    std::cout << "3. Решение квадратных уравнений (вводится выражение вида ax^2 + bx + c)" << std::endl;
    std::cout << "4. Сумма больших целых неотрицательных чисел" << std::endl;
    std::cout << std::endl;
}
int main() {
    std::cout << "Добро пожаловать в калькулятор!" << std::endl;
    while (true) {
        PrintMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                std::cout << "Выберите режим и введите соответствующее число: (1 - обычные операции, 2 - дополнительные операции): ";
                int mode;
                std::cin >> mode;

                if (mode == 1) {
                    std::cout << "Введите выражение для вычисления: ";
                    std::string expression;
                    std::cin.ignore();
                    std::getline(std::cin, expression);
                    trim(expression);
                    try {
                        auto postfix = InfixToPostfix(expression);
                        double result = EvaluatePostfix(postfix);
                        std::cout << "Результат: " << result << std::endl;
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Ошибка: " << e.what() << std::endl;
                    }
                }
                else if (mode == 2) {
                    try {
                        std::cout << "Выберите операцию:" << std::endl;
                        std::cout << "1) Перемножение матриц" << std::endl;
                        std::cout << "2) Нахождение делителей числа (выводит простые делители и их степени)" << std::endl;
                        std::cout << "3) Решение квадратных уравнений" << std::endl;
                        std::cout << "4) Сумма больших целых неотрицательных чисел" << std::endl;
                        int a123;
                        std::cin >> a123;
                        if (a123 == 1) {
                            size_t w1, w2, l1, l2;
                            std::cout << "Введите размеры первой матрицы" << std::endl;
                            std::cin >> w1 >> l1;
                            std::vector<std::vector<int32_t>> lhs(w1, std::vector<int32_t>(l1, 0));
                            std::cout << "Введите первую матрицу построчно" << std::endl;
                            for (size_t i = 0; i < w1; i++) {
                                for (size_t j = 0; j < l1; j++) {
                                    std::cin >> lhs[i][j];
                                }
                            }
                            std::cout << "Введите размеры второй матрицы" << std::endl;
                            std::cin >> w2 >> l2;
                            while (l1 != w2) {
                                std::cerr << "Количество столбцов первой матрицы должно совпадать с количеством строк второй" << std::endl;
                                std::cout << "Если хотите изменить размеры первой матрицы введите 1" << std::endl;
                                std::cout << "Если хотите изменить размеры второй матрицы введите 2" << std::endl;
                                std::cout << "Если хотите выйти введите 3" << std::endl;
                                int turn;
                                std::cin >> turn;
                                if (turn == 1) {
                                    std::cin >> w1 >> l1;
                                }
                                if (turn == 2) {
                                    std::cin >> w2 >> l2;
                                }
                                if (turn == 3) {
                                    break;
                                }
                            }
                            std::cout << "Введите вторую матрицу построчно" << std::endl;
                            std::vector<std::vector<int32_t>> rhs(w2, std::vector<int32_t>(l2, 0));
                            for (size_t i = 0; i < w2; i++) {
                                for (size_t j = 0; j < l2; j++) {
                                    std::cin >> rhs[i][j];
                                }
                            }
                            std::vector<std::vector<int32_t>> result = Calculator::MultiplyMatrices(lhs, rhs);
                            std::cout << "Результат: " << std::endl;
                            for (auto & i : result) {
                                for (const int j : i) {
                                    std::cout << j << " ";
                                }
                                std::cout << std::endl;
                            }
                            std::cout << std::endl;

                        } else if (a123 == 2) {
                            int64_t num;
                            std::cout << "Введите число: " << std::endl;
                            std::cin >> num;
                            std::vector<std::pair<int64_t, int32_t>> result = Calculator::Factorize(num);
                            std::cout << "Результат: " << std::endl;
                            for (const auto & i : result) {
                                std::cout << i.first << " " << i.second << std::endl;
                            }
                        } else if (a123 == 3) {
                            std::cout << "Введите коэффициенты выражения ax^2 + bx + c" << std::endl;
                            std::cout << "Введите a, b и c:" << std::endl;
                            int a, b, c;
                            std::cin >> a >> b >> c;
                            std::cout << "Результат: " << std::endl;
                            Calculator::SolveQuadratic(a, b, c);
                            std::cout << std::endl;
                        } else if (a123 == 4) {
                            std::cout << "Введите первое число:" << std::endl;
                            std::string first;
                            std::cin >> first;
                            std::cout << "Введите второе число:" << std::endl;
                            std::string second;
                            std::cin >> second;
                            const std::string result = Calculator::LongSum(first, second);
                            std::cout << "Результат: " << std::endl;
                            std::cout << result << std::endl;
                        } else {
                            std::cerr << "Ошибка: введено неправильное число" << std::endl;
                        }
                    } catch (const std::exception& e) {
                        std::cerr << "Ошибка: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "Ошибка: введено неправильное число" << std::endl;
                }
                break;
            }
            case 2: {
                PrintHelp();
                break;
            }
            case 3: {
                std::cout << "Выход из программы." << std::endl;
                return 0;
            }
            default:
                std::cerr << "Неверный выбор, попробуйте снова." << std::endl;
        }
    }
}
