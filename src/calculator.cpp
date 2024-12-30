#include "../include/calculator.h"
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>

double Calculator::calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '^': return BinPow(static_cast<int>(num1), static_cast<int64_t>(num2));
        case '/':
            if (num2 == 0) throw std::invalid_argument("Деление на ноль");
        return num1 / num2;
        case '%':
            if (num2 == 0) throw std::invalid_argument("Деление на ноль");
        return static_cast<int>(num1) % static_cast<int>(num2);
        case '&':
            if (num2 == 0) throw std::invalid_argument("Деление на ноль");
        return static_cast<int>(num1) / static_cast<int>(num2);
        default: throw std::invalid_argument("Неизвестный оператор");
    }
}

double Calculator::calculateUnary(double num, const char operation) {
    if (operation == '_') {
        if (num < 0) throw std::invalid_argument("Квадратный корень из отрицательного числа");
        return sqrt(num);
    }
    if (operation == '|') {
        return fabs(num);
    }
    if (operation == '-') {
        return -num;
    }
    throw std::invalid_argument("Неверная операция");
}
std::pair<double, double> TwoSum(double a, double b) {
    const double x = a + b;
    const double z = x - a;
    const double y = a - (x - z) + (b - z);
    return std::make_pair(x, y);
}

double Calculator::AccurateSum(const std::vector<double>& data) {
    double s = data[0];
    double del = 0.0;
    for (int i = 1; i < data.size(); ++i) {
        const std::pair<double, double> p = TwoSum(s, data[i]);
        s = p.first;
        const double q = p.second;
        del += q;
    }
    const double res = s + del;
    return res;
}

int32_t Calculator::BinPow(int32_t a, int64_t b) { // NOLINT
    int64_t result = 0;
    if (b == 0) {
        result = 1;
    }

    else {
        if (b % 2 == 1) {
            result = BinPow(a, b - 1) * a;
        }

        else {
            const int64_t t = BinPow(a, b / 2);
            result = t * t;
        }
    }
    return static_cast<int32_t>(result);
}

std::string Calculator::LongSum(const std::string& a, const std::string& b) {
    const size_t p = a.length();
    const size_t t = b.length();
    const int pi = static_cast<int>(p);
    const int ti = static_cast<int>(t);
    const int k = std::max(pi, ti);
    std::vector<int32_t> c;
    int32_t odin = 0;
    for (int i = 0; i < k; i++) {
        if (i > pi - 1) {
            c.push_back(((b[ti - i - 1] - '0') + odin) % 10);
            odin = ((b[ti - i - 1] - '0') + odin) / 10;
        } else if (i > ti - 1) {
            c.push_back(((a[pi - i - 1] - '0') + odin) % 10);
            odin = ((a[pi - i - 1] - '0') + odin) / 10;
        } else {
            c.push_back(((a[pi - i - 1] - '0') + (b[ti - i - 1] - '0') + odin) % 10);
            odin = ((a[pi - i - 1] - '0') + (b[ti - i - 1] - '0') + odin) / 10;
        }
    }
    if (odin > 0) {
        c.push_back(odin);
    }
    std::reverse(c.begin(), c.end());
    std::string s;
    const size_t n = c.size();
    for (size_t i = 0; i < n; i++) {
        s += std::to_string(c[i]);
    }
    return s;
}

std::vector<std::vector<int32_t>> Calculator::MultiplyMatrices(
    const std::vector<std::vector<int32_t>>& lhs, const std::vector<std::vector<int32_t>>& rhs) {
    const size_t min = std::min(lhs.size(), rhs.size());
    size_t min_size = 0;
    size_t size1 = 0;
    if (min > 0) {
        min_size = std::min(rhs[0].size(), lhs[0].size());
        size1 = rhs[0].size();
    }
    if (min_size > 0) {
        std::vector<std::vector<int32_t>> result(
            lhs.size(), std::vector<int32_t>(rhs[0].size(), 0));
        for (size_t i = 0; i < lhs.size(); i++) {
            for (size_t j = 0; j < rhs[0].size(); j++) {
                for (size_t k = 0; k < lhs[0].size(); k++) {
                    result[i][j] += lhs[i][k] * rhs[k][j];
                }
            }
        }
        return result;
    }
    return std::vector<std::vector<int32_t>>(lhs.size(), std::vector<int32_t>(size1, 0));
}

int Divide(int64_t& numerator, int& denominator, int& counter) { // NOLINT
    if (numerator % denominator == 0) {
        numerator /= denominator;
        counter = Divide(numerator, denominator, counter);
        counter++;
    }
    return counter;
}

std::vector<std::pair<int64_t, int>> Calculator::Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> result;
    int count = 0;
    int64_t numerator = x;
    if (x % 2 == 0) {
        int den = 2;
        result.emplace_back(2, Divide(numerator, den, count));
        count = 0;
    }
    int i = 3;
    while (numerator > 1 and static_cast<int64_t>(i) * static_cast<int64_t>(i) <= x) {
        if (numerator % i == 0) {
            result.emplace_back(i, Divide(numerator, i, count));
            count = 0;
        }
        i += 2;
    }
    if (numerator > 1 || result.empty()) {
        result.emplace_back(numerator, 1);
    }
    return result;
}

Roots Calculator::SolveQuadratic(const int a, const int b, const int c) {
    const auto new_a = static_cast<double>(a);
    const auto new_b = static_cast<double>(b);
    const auto new_c = static_cast<double>(c);
    const double discriminant = (new_b * new_b) - (4 * new_a * new_c);
    Roots roots{};
    if (a * a + b * b + c * c == 0) {
        roots.count = RootCount::kInf;
        std::cout << "Бесконечно много корней" << std::endl;
    } else if (discriminant < 0 or a * a + b * b == 0) {
        roots.count = RootCount::kZero;
        std::cout << "Нет корней" << std::endl;
    } else if (a == 0) {
        roots.count = RootCount::kOne;
        std::cout << "Один корень" << std::endl;
        roots.first = -new_c / new_b;
        std::cout << roots.first << std::endl;
    } else if (discriminant == 0) {
        const double root1 = (-new_b) / (2 * new_a);
        roots.count = RootCount::kOne;
        std::cout << "Один корень" << std::endl;
        roots.first = root1;
        std::cout << roots.first << std::endl;
    } else if (discriminant > 0) {
        roots.count = RootCount::kTwo;
        std::cout << "Два корня" << std::endl;
        double root1 = 0;
        double root2 = 0;
        if (a < 0 and new_b > 0) {
            root1 = (-new_b + sqrt(discriminant)) / (2 * new_a);
            root2 = (-new_b - sqrt(discriminant)) / (2 * new_a);
        } else {
            root1 = (-new_b - sqrt(discriminant)) / (2 * new_a);
            root2 = (-new_b + sqrt(discriminant)) / (2 * new_a);
        }
        roots.first = root1;
        roots.second = root2;
        std::cout << roots.first << std::endl;
        std::cout << roots.second << std::endl;
    }
    return roots;
}