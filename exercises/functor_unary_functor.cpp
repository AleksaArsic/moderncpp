#include <iostream>
#include <vector>
#include <algorithm>
#include <concepts>

template <std::integral VEC_NUMTYPE>
using Numbers = std::vector<VEC_NUMTYPE>;

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
        [[nodiscard]] constexpr VEC_NUMTYPE operator()(const VEC_NUMTYPE x) const
        {
            return x * x;   
        }
};

template <std::integral VEC_NUMTYPE>
void printNumbers(const Numbers<VEC_NUMTYPE>& numbers)
{
    for(const auto& n : numbers)
    {
        std::cout << n << ", ";   
    }
    std::cout<< std::endl;
}


int main() 
{     
    IncreasingNumberGenerator<int> ing;
    // Initialize vector with 100 default values = 0
    Numbers<int> numbers(100);
    printNumbers(numbers);

    std::generate(std::begin(numbers), std::end(numbers), ing);
    printNumbers(numbers);
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), ToSquare<int>());
    printNumbers(numbers);


    return 0; 
}