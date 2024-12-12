#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>

using Numbers = std::vector<int>;

template <std::integral NUMTYPE>
class IncreasingNumberGenerator
{
    public:
        [[nodiscard]] constexpr NUMTYPE operator()()
        {
            return number++;
        }
    private:
        NUMTYPE number { 0 };
    
};

template <std::integral VEC_NUMTYPE>
class ToSquare 
{
    public:
        [[nodiscard]] constexpr VEC_NUMTYPE operator()(const VEC_NUMTYPE value) const noexcept
        {
            return value * value;   
        }
};

template <std::integral VEC_NUMTYPE>
class IsOddNumber
{
    public:
        [[nodiscard]] constexpr bool operator()(const VEC_NUMTYPE value) const noexcept
        {
            return (value % 2) != 0;
        }
};

// Binary functor with boolean return value is called "Binary Predicate"
template <std::integral VEC_NUMTYPE>
class IsGreaterOrEqual
{
    public:
        [[nodiscard]] constexpr bool operator()(const VEC_NUMTYPE value1, const VEC_NUMTYPE value2) const noexcept
        {
            return value1 >= value2;   
        }
};

template <std::integral VEC_NUMTYPE>
class PrintTheNumber
{
    public:
        constexpr void operator()(const VEC_NUMTYPE value) const noexcept
        {
            std:: cout << value << ", ";   
        }
};

int main() 
{     
    // Initialize vector with 100 default values = 0
    Numbers numbers(100);
    IncreasingNumberGenerator<Numbers::value_type> ing;
    std::for_each(std::begin(numbers), std::end(numbers), PrintTheNumber<Numbers::value_type>());

    std::generate(std::begin(numbers), std::end(numbers), ing);
    std::for_each(std::begin(numbers), std::end(numbers), PrintTheNumber<Numbers::value_type>());
    std::cout << std::endl;
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), ToSquare<Numbers::value_type>());
    std::for_each(std::begin(numbers), std::end(numbers), PrintTheNumber<Numbers::value_type>());
    std::cout << std::endl;
    std::erase_if(numbers, IsOddNumber<Numbers::value_type>());
    std::for_each(std::begin(numbers), std::end(numbers), PrintTheNumber<Numbers::value_type>());
    std::cout << std::endl;

    int a = 3;
    int b = 1;
    std::cout << "Is 'a' greater than or equal to 'b'? : " << IsGreaterOrEqual<int>()(a, b) << std::endl; 

    return 0; 
}