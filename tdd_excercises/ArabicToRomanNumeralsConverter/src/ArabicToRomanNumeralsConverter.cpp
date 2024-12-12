#include "ArabicToRomanNumeralsConverter.h"

namespace arabicToRomanNumeralsConverter
{
    std::string ArabicToRomanNumeralsConverter::convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
    {

        std::string returningRomanNumeral = "";

        for (const ArabicToRomanMapping& atrm : arabicToRomanMappings)
        {
            while (arabicNumber >= atrm.arabicNumber)
            {
                returningRomanNumeral += atrm.romanNumeral;
                arabicNumber -= atrm.arabicNumber;
            }
        }

        return returningRomanNumeral;
    }
}