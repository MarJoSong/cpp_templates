#include <iostream>

void print1()
{
}

template <typename T, typename... Ts> void print1(T firstArg, Ts... args)
{
    std::cout << firstArg << "\n";
    print1(args...);
}

// 如果两个模板参数只存在尾部参数包的区别，则首选无尾部参数包的函数模板
template <typename T> void print2(T arg)
{
    std::cout << arg << "\n";
}

template <typename T, typename... Ts> void print2(T firstArg, Ts... args)
{
    std::cout << firstArg << " ";
    print2(args...);
}

template <typename T, typename... Ts> void print3(T firstArg, Ts... args)
{
    std::cout << sizeof...(Ts) << "\n";
    std::cout << sizeof...(args) << "\n";
}

template <typename T> void print4(T arg)
{
    std::cout << "1:" << arg << "\n";
}

template <typename T, typename... Ts> void print4(T firstArg, Ts... args)
{
    std::cout << sizeof...(args) + 1 << ":" << firstArg << " ";
    print4(args...);
}

template <typename T, typename... Ts> void print5(T firstArg, Ts... args)
{
    std::cout << sizeof...(args) + 1 << ":" << firstArg << " ";
    if (sizeof...(args) > 0)
    {
        print5(args...); // 编译报错
    }
    else
    {
        std::cout << "\n";
    }
}

int main(int, char **)
{
    std::string s{"hello"};
    std::cout << "================print1================"
              << "\n";
    print1(7.5, 200, s);
    std::cout << "================print2================"
              << "\n";
    print2(7.5, 200, s);
    std::cout << "================print3================"
              << "\n";
    print3(7.5, 200, s);
    std::cout << "================print4================"
              << "\n";
    print4(7.5, 200, s);
    std::cout << "================print5================"
              << "\n";
    // print5(7.5, 200, s);

    return 0;
}