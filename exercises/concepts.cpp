#include <iostream>
#include <concepts>

template <typename T>
concept Copyable = 
    std::copy_constructible<T> &&
    std::movable<T> &&
    std::assignable_from<T&, const T&> &&
    std::assignable_from<T&, const T&> &&
    std::assignable_from<T&, const T>;
    
class CopyableType {};

class NonCopyableType
{
    public: 
        NonCopyableType() = default;
        NonCopyableType(const NonCopyableType&) = delete;
        NonCopyableType& operator=(const NonCopyableType&) = delete;
};

template <typename T>
void function(T& t) requires Copyable<T>
{
    // empty  
};

int main() 
{ 
    CopyableType a;
    function(a); // OK
    
    NonCopyableType b;
    //function(b); // Illegal
    
    return 0; 
}