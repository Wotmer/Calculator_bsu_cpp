#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

enum class RootCount : int8_t { kZero, kOne, kTwo, kInf };

struct Roots {
    RootCount count;
    double first;
    double second;
};

class Calculator {
public:
    static double calculate(double num1, double num2, char operation);
    static double calculateUnary(double num, char operation);
    static double AccurateSum(const std::vector<double>& data);
    static int32_t BinPow(int32_t a, int64_t b);
    static std::string LongSum(const std::string &a, const std::string &b);
    static std::vector<std::vector<int32_t>> MultiplyMatrices(
        const std::vector<std::vector<int32_t>> &lhs, const std::vector<std::vector<int32_t>> &rhs);
    static std::vector<std::pair<int64_t, int>> Factorize(int64_t x);
    static Roots SolveQuadratic(int a, int b, int c);
};
#endif // CALCULATOR_H