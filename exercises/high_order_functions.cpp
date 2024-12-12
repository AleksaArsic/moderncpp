#include <iostream>
#include <vector>
#include <concepts>

using Numbers = std::vector<int>;

template <typename CONTAINERTYPE, typename UNARYFUNCTION>
constexpr void myForEach(CONTAINERTYPE& container, const UNARYFUNCTION& unaryFunction)
{
    for(auto& element : container)
    {
        unaryFunction(element);   
    }
}

template <typename CONTAINERTYPE, typename UNARYOPERATION>
constexpr void myTransform(CONTAINERTYPE& container, const UNARYOPERATION& unaryOperation)
{
    for(auto& element : container)
    {
        element = unaryOperation(element);   
    }
}

template <typename T>
concept NUMBERTYPE = std::integral<T> || std::floating_point<T>;

template <typename T> requires NUMBERTYPE<T>
class ToSquare
{
    public:
        constexpr T operator()(const T number) const noexcept
        {
            return number * number;   
        }
};

template <typename T> requires NUMBERTYPE<T>
class PrintTheNumber
{
    public:
        constexpr void operator()(const T number) const noexcept
        {
            std::cout << number << " ";
        }
};


int main() 
{     
    Numbers numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    myForEach(numbers, PrintTheNumber<Numbers::value_type>());    
    std::cout << std::endl;
    
    std::function<void(Numbers::value_type)> printNumbersOnStd = PrintTheNumber<Numbers::value_type>();
    
    myTransform(numbers, ToSquare<Numbers::value_type>());
    myForEach(numbers, printNumbersOnStd);    
    std::cout << std::endl;
    
    
    return 0; 
}