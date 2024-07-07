#include <iostream>
#include <ostream>
#include <type_traits>
#include <vector>

template <typename... Ts> auto fold_sum(Ts... s)
{
    // ((s1 + s2) + s3)...
    return (... + s);

    // (s1 + (...(sn-1 + sn)))
    // return (s + ...)
}

template <typename... Ts> auto fold_sum_init_10(Ts... s)
{
    // (((10 + s1) + s2) + s3)...
    return (10 + ... + s);
}

struct Node
{
    int value;
    Node *left_;
    Node *right_;
    Node(int i = 0) : value(i), left_(nullptr), right_(nullptr)
    {
    }
};

auto left = &Node::left_;
auto right = &Node::right_;

template <typename T, typename... Ts> Node *traverse(T np, Ts... paths)
{
    return (np->*...->*paths);
}

template <typename T> class AddSpace
{
  public:
    AddSpace(T const &r) : ref(r)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, AddSpace<T> s)
    {
        return os << s.ref << " ";
    }

  private:
    T const &ref;
};

template <typename... Ts> void print(Ts const &...args)
{
    (std::cout << ... << AddSpace(args)) << "\n";
}

template <typename... Ts> void print_double(Ts... args)
{
    print(args + args...);
}

template <typename... Ts> void print_plus_one(Ts... args)
{
    // 编译报错，把 1... 当成一个字面量了
    // print(args + 1...);

    print(args + 1 ...);
    print((args + 1)...);
}

template <typename T1, typename... TN> constexpr bool isHomogeneous(T1, TN...)
{
    // 被扩展为 std::is_same_v<T1, T2> && std::is_same_v<T1, T3> && ... && std::is_same_v<T1, TN>
    return (std::is_same_v<T1, TN> && ...);
}

template <typename V, typename... Idx> void printElems(V const &v, Idx... idx)
{
    print(v[idx]...);
}

// 非类型模板参数声明为参数包
template <std::size_t... Idx, typename V> void printElems2(V const &v)
{
    print(v[Idx]...);
}

int main(int, char **)
{
    std::cout << fold_sum(1, 2, 3) << "\n";
    std::cout << fold_sum_init_10(1, 2, 3) << "\n";

    Node *root = new Node;
    root->left_ = new Node(1);
    root->left_->right_ = new Node(2);

    Node *node = traverse(root, left, right);
    // root ->* left ->* right

    print(200, 7.5, "hello");
    print_double(200, 7.5, std::string("hello"));

    print_plus_one(200, 7.5);

    std::cout << std::boolalpha << isHomogeneous(200, 100, 110) << "\n";
    std::cout << std::boolalpha << isHomogeneous(200, 100, 1.1) << "\n";

    std::vector<int> vecs{1, 2, 3, 4, 5};
    printElems(vecs, 1, 3, 4);
    printElems2<1, 3, 4>(vecs);
}