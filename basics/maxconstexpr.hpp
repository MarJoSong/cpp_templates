template <typename T1, typename T2> auto max(T1 a, T2 b)
{
    return b < a ? a : b;
}

template <typename T1, typename T2> constexpr auto max_const(T1 a, T2 b)
{
    return b < a ? a : b;
}