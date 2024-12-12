#include <iostream>
#include <string>

class DivisionByZeroException : public std::exception
{
    public:
        DivisionByZeroException() = delete;
        
        explicit DivisionByZeroException(const int dividend)
        {
            buildErrorMessage(dividend);
        }
        
        const char* what() const noexcept override
        {
            return errorMessage.c_str();   
        }
    private:
        void buildErrorMessage(const int dividend)
        {
            errorMessage = "A division with dividend = ";
            errorMessage += std::to_string(dividend);
            errorMessage += ", and divisor = 0, is not allowed (Division by zero!).";
        }
        
        std::string errorMessage;
};

int divide(const int dividend, const int divisor)
{
    if (0 == divisor)
    {
        throw DivisionByZeroException(dividend);   
    }
    
    return dividend / divisor;   
}

int main() 
{ 
    try
    {
        divide(10, 0);   
    }
    catch (const DivisionByZeroException& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0; 
}