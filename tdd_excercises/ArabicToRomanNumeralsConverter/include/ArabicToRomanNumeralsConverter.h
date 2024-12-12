#include <string>
#include <array>

namespace arabicToRomanNumeralsConverter
{
    class ArabicToRomanNumeralsConverter
    {
    public:
        ArabicToRomanNumeralsConverter() = default;
        std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber);

    private:
        struct ArabicToRomanMapping
        {
            unsigned int arabicNumber;
            std::string romanNumeral;
        };

        static constexpr int numberOfRomanMappings{ 13 };

        const std::array<ArabicToRomanMapping, numberOfRomanMappings> arabicToRomanMappings
        {
            ArabicToRomanMapping {1000,  "M" },
            ArabicToRomanMapping { 900,  "CM"},
            ArabicToRomanMapping { 500,  "D" },
            ArabicToRomanMapping { 400,  "CD" },
            ArabicToRomanMapping { 100,  "C" },
            ArabicToRomanMapping {  90,  "XC"},
            ArabicToRomanMapping {  50,  "L" },
            ArabicToRomanMapping {  40,  "XL"},
            ArabicToRomanMapping {  10,  "X" },
            ArabicToRomanMapping {   9,  "IX"},
            ArabicToRomanMapping {   5,  "V" },
            ArabicToRomanMapping {   4,  "IV"},
            ArabicToRomanMapping {   1,  "I" }
        };
    };
}