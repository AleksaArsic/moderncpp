#include <iostream>
#include <type_traits>

// Defines the MksUnit in the following format
// MksUnit<M, K, S>
// e.g. Volume = MksUnit<3, 0, 0> = m^3
// e.g. Speed = MksUnit<1, 0, -1> = m/s
// e.g. Acceleration = MksUnit<1, 0, -2> = m/s^2
template <int M, int K, int S>
struct MksUnit 
{
    enum { metre = M, kilogram = K, second = S };  
};

// defines the check for IsMksUnitType as std::false_type if not instantiated 
// with <MksUnit<M, K, S>
template <typename T>
struct IsMksUnitType : std::false_type { };

// defines the check for IsMksUnitType as std::true_type instantiated 
// with <MksUnit<M, K, S> 
template <int M, int K, int S>
struct IsMksUnitType<MksUnit<M, K, S>> : std::true_type { };

// concept is a named set of requirements that can be applied on 
// the template arguments and are evaluated at the compile time.
// This way they are becoming the part of template interface.
template <typename T> 
concept MksUnitType = IsMksUnitType<T>::value;

// Value needs to be declared with the MksUnitType<MksUnit<M, K, S>::value == true
// requires specifies constraints on template arguments or on a function decalration
template <typename T> requires MksUnitType<T>
class Value 
{
    public:
        constexpr explicit Value(const long double magnitude) noexcept : magnitude(magnitude)
        { }
        
        constexpr long double getMagnitude() const noexcept 
        {
            return magnitude;   
        }
        
        // setMagnitude() or overload operator=
        constexpr void setMagnitude(long double value) noexcept
        {
            magnitude = value;   
        }
        
    private:
        long double magnitude { 0.0 };
};

using Momentum = Value<MksUnit<1, 1, -1>>;
// Illegal! 
// error: template argument for template type parameter must be a type
// template parameter is declared here template <typename T> requires MksUnitType<T>
//using Force = Value<3>;

class SpacecraftTrajectoryControl
{
    public:
        
        void applyMomentumToSpacecraftBody(Momentum& momentumValue)
        {
            overallMomentum.setMagnitude(overallMomentum.getMagnitude() + momentumValue.getMagnitude());
        }
        
        Momentum getOverallMomentum() const
        {
            return overallMomentum;   
        }
        
        friend std::ostream& operator<<(std::ostream& os, SpacecraftTrajectoryControl stc);
    private:
        Momentum overallMomentum { 0.0 };
};

std::ostream& operator<<(std::ostream& os, SpacecraftTrajectoryControl stc)
{
    Momentum overallMomentum = stc.getOverallMomentum();
    
    os << overallMomentum.getMagnitude();
    
    return os;
}

int main() 
{ 
    SpacecraftTrajectoryControl trajectoryControl;
    // Illegal!
    //long double momentum = 12.3;
    // OK
    Momentum momentum {12.3};
    
    trajectoryControl.applyMomentumToSpacecraftBody(momentum);
    
    std::cout << "Spacecraft trajectory control overall momentum magnitude = " << trajectoryControl << std::endl;
    
    return 0; 
}