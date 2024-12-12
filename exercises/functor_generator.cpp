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
void populateNumbers(Numbers<VEC_NUMTYPE>& numbers, IncreasingNumberGenerator<VEC_NUMTYPE>& ing)
{
    for(auto& n : numbers)
    {
        n = ing();
    }
}

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
    // Illegal
    // error: no matching function for call to 'populateNumbers'
    // note: candidate template ignored: deduced conflicting types for parameter 'VEC_NUMTYPE' ('int' vs. 'double')
    //IncreasingNumberGenerator<double> ing;

    // Initialize vector with 100 default values = 0
    Numbers<int> numbers(100);
    printNumbers(numbers);

    populateNumbers(numbers, ing);
    printNumbers(numbers);


    return 0; 
}