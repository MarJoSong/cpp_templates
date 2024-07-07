#include "max1.hpp"

#include <iostream>

int main()
{
    int i = 42;
    std::cout << "max(7, i): " << max2(7, i) << "\n";

    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1, f2): " << max2(f1, f2) << "\n";

    std::string s1 = "mathmetics";
    std::string s2 = "math";
    std::cout << "max(s1, s2): " << max2(s1, s2) << "\n";

    std::cout << ::max2<double>(1, 2.1) << std::endl; // 必须显式指定模板参数类型

    std::cout << ::max3<double, int, double>(1, 2.1) << std::endl;
    std::cout << ::max3<double>(1, 2.1) << std::endl; // 如果返回值类型式第一个参数，可以只显式指定它，调用参数自动推导即可

    f();
    f(1);
}