#include "maxconstexpr.hpp"

#include <array>
#include <string>

int main()
{
    // int a[::max(sizeof(char), 1000ull)]; // 表达式的计算结果不是常数
    int b[::max_const(sizeof(char), 1000u)];

    std::array<std::string, ::max_const(sizeof(char), 1000u)> arr;
}