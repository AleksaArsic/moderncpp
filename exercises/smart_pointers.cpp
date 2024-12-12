#include <iostream>
#include <string>
#include <memory>

int main()
{
    int a = 3;
    int b = 5;
    
    std::unique_ptr<int> unqPtr = std::make_unique<int>(a);
    std::shared_ptr<int> shrPtr = std::make_shared<int>(a); 
    

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    
    std::cout << "*unqPtr (a) = " << *unqPtr << std::endl;
    std::cout << "*shrPtr (a) = " << *shrPtr << std::endl;
    
    // Ilegal action(s)
    //std::unique_ptr<int> unqPtr2 = unqPtr;
    //std::shared_ptr<int> shrPtr2 = unqPtr;
    std::unique_ptr<int> unqPtr2 = std::make_unique<int>(a);
    unqPtr2 = std::move(unqPtr);
    std::cout << "[std::move] *unqPtr (a) = " << *unqPtr << std::endl;
    std::cout << "[std::move] *unqPtr2 (a) = " << *unqPtr2 << std::endl;
    
    std::shared_ptr<int> shrPtr2 = shrPtr;
    std::cout << "*shrPtr (a) = " << *shrPtr << std::endl;
    std::cout << "*shrPtr2 (a) = " << *shrPtr2 << std::endl;    
    
}