#include "gtest/gtest.h"
#include <string>
#include "ArabicToRomanNumeralsConverter.h"

class RomanNumeralAssert
{
    public:
        RomanNumeralAssert() = delete;

        explicit RomanNumeralAssert(const unsigned int arabicNumber) : arabicNumberToConvert(arabicNumber)
        { }

        void isConvertedToRomanNumeral(std::string_view expectedRomanNumeral)
        {
            ASSERT_EQ(expectedRomanNumeral, atrnConverter.convertArabicNumberToRomanNumeral(arabicNumberToConvert));
        }
    private:
        const unsigned int arabicNumberToConvert;
        arabicToRomanNumeralsConverter::ArabicToRomanNumeralsConverter atrnConverter;
};

RomanNumeralAssert checkIf(const unsigned int arabicNumber)
{
    RomanNumeralAssert assert{ arabicNumber };

    return assert;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(ArabicToRomanNumeralsConverterTestCase, conversionOfArabicNumbersToRomanNumerals_Works)
{
    checkIf(1).isConvertedToRomanNumeral("I");
    checkIf(2).isConvertedToRomanNumeral("II");
    checkIf(3).isConvertedToRomanNumeral("III");

    checkIf(4).isConvertedToRomanNumeral("IV");

    checkIf(5).isConvertedToRomanNumeral("V");
    checkIf(6).isConvertedToRomanNumeral("VI");

    checkIf(9).isConvertedToRomanNumeral("IX");

    checkIf(10).isConvertedToRomanNumeral("X");
    checkIf(20).isConvertedToRomanNumeral("XX");
    checkIf(30).isConvertedToRomanNumeral("XXX");
    checkIf(33).isConvertedToRomanNumeral("XXXIII");
    checkIf(37).isConvertedToRomanNumeral("XXXVII");

    checkIf(40).isConvertedToRomanNumeral("XL");
    checkIf(50).isConvertedToRomanNumeral("L");

    checkIf(90).isConvertedToRomanNumeral("XC");

    checkIf(100).isConvertedToRomanNumeral("C");
    checkIf(200).isConvertedToRomanNumeral("CC");
    checkIf(300).isConvertedToRomanNumeral("CCC");

    checkIf(400).isConvertedToRomanNumeral("CD");
    
    checkIf(500).isConvertedToRomanNumeral("D");
    checkIf(552).isConvertedToRomanNumeral("DLII");

    checkIf(900).isConvertedToRomanNumeral("CM");
    checkIf(994).isConvertedToRomanNumeral("CMXCIV");

    checkIf(1000).isConvertedToRomanNumeral("M");
    checkIf(2000).isConvertedToRomanNumeral("MM");
    checkIf(3000).isConvertedToRomanNumeral("MMM");
    checkIf(3333).isConvertedToRomanNumeral("MMMCCCXXXIII");

}