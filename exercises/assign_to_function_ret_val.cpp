#include <iostream> 

int* fun() //fun defined to return pointer to int (lvalue)
{ 
    static int x = 10; 
    return &x; // returning address of static int
} 

int& fun2() // fun2 defined to return reference to int (lvalue)
{
  static int x = 10;
  return x; // returning the reference to the static int (lvalue)
}


int main() 
{ 
    *fun() = 30; // execute fun(), take its return value and dereference it,
                 // yielding an lvalue, which you can assign to. 
                 
    fun2() = 15; // execute fun2()
                // yielding an lvalue, which you can assign to.
    
    std::cout << *fun() << std::endl;  // you also need to dereference here
    std::cout << fun2() << std::endl;
        
    return 0; 
}