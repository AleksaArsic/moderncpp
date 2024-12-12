#include <iostream> 

class ArtificialDouble
{
    public:
        constexpr ArtificialDouble(long double d) : value(d) 
        { }
        
        long double getValue() const
        {
            return value;    
        }
        
        friend constexpr ArtificialDouble operator""_d(long double d);
        
    private:
        long double value;
};

constexpr ArtificialDouble operator""_d(long double d)
{
    return ArtificialDouble(d);   
}

std::ostream& operator<<(std::ostream& os, ArtificialDouble ad)
{
    os << ad.getValue();
    
    return os;
}

int main() 
{ 
    ArtificialDouble d = { 3.4 };
    ArtificialDouble d2 = 3.4_d;
    
    std::cout << "Artificial double = " << d << std::endl;
    std::cout << "Artificial double2 = " << d2 << std::endl;
    
    return 0; 
}