#include <iostream>
#include "ArabicToRomanNumeralsConverter.h"

int main()
{
    arabicToRomanNumeralsConverter::ArabicToRomanNumeralsConverter atrnConverter;

    std::cout << atrnConverter.convertArabicNumberToRomanNumeral(334) << std::endl;

    return 0;
}