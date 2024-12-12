#include <iostream>
#include <vector>
#include <concepts>

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

int main() 
{     
    std::string string1 = "Aleksa";
    std::string string2 = "Arsic";
    
    auto add = []<Number T>(const T value1, const T value2) 
        {
            return value1 + value2;   
        };
        
    auto result1 = add(1, 2);
    auto result2 = add(2.0, 3.0);
    auto result3 = add('a', 'b'); // will be deduced to 'int', use -> T in lambda declaration to deduce 'char'
    
    // Illegal -> strings are not integral, nor floating point types
    //auto result4 = add(string1, string2);
        
    std::cout << result1 << " " << result2 << " " << result3 << std::endl;
    
    return 0; 
}