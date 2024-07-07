#include <iostream>
#include <string>


template <typename T>
T max2(T a, T b)
{
    return b < a ? a : b;
}

template <typename RT, typename T1, typename T2>
RT max3(T1 a, T2 b)
{
    return b < a ? a : b;
}

template <typename T1, typename T2>
auto max_auto(T1 a, T2 b)
{
    return b < a ? a : b;
}

template <typename T = std::string>
T f(T param = "hello")
{
    std::cout << param << std::endl;
    return param;
}