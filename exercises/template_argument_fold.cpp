#include <iostream>
#include <concepts>

// Left fold
// A B C D
// e.g. accumulate = ((A + B) + C ) + D

// Right fold
// A B C D
// e.g. accumulate = A + (B + (C + D))

// Example of left fold
template <typename T, typename... PACK>
concept Number = std::integral<T> || std::floating_point<T>;

template <typename T, typename... PACK> requires Number<T, PACK...>
T subtractFold(T first, PACK... rest)
{
    return (first - ... - rest);    
}

int main() 
{     
    const int result = subtractFold(1000, 55, 12, 333, 1, 12);
    
    std::cout << "The result is: " << result << std::endl;
    
    return 0; 
}