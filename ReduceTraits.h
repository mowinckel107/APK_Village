template<typename T>
struct ReduceTraits;

template<>
struct ReduceTraits<char>
{
    using Result = int;
    static Result const zero = 0;
};

template<>
struct ReduceTraits<short>
{
    using Result = int;
    static Result const zero = 0;
};

template<>
struct ReduceTraits<int>
{
    using Result = long;
    static Result const zero = 0l;
};

template<>
struct ReduceTraits<unsigned int>
{
    using Result = unsigned long;
    static Result const zero = 0ul;
};

template<>
struct ReduceTraits<float>
{
    using Result = double;
    static Result constexpr zero = 0.0;
};