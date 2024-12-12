#include <iostream>
#include <string>

int main()
{
    int a = 3;
    
    int* ptr = &a;
    int& ref = a;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    std::cout << "ref = " << ref << std::endl << std::endl;

    a = 5;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    std::cout << "ref = " << ref << std::endl << std::endl;   
    
    int b = 8;
    
    ref = b;

    std::cout << "a = " << a << std::endl;   
    std::cout << "b = " << b << std::endl;
    std::cout << "ref = " << ref << std::endl << std::endl;

    return 0;
}