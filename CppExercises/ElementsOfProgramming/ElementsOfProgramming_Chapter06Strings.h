#pragma once

#include <string>

void ElementsOfProgrammingChapter06Strings();

void ElementsOfProgrammingChapter06Strings_CheckIsPalindrome();
void ElementsOfProgrammingChapter06Strings_StringToInt();
void ElementsOfProgrammingChapter06Strings_IntToString();
void ElementsOfProgrammingChapter06Strings_BaseConversionDigitString();
void ElementsOfProgrammingChapter06Strings_OrderingNumberOfSpreadsheetColumn();


bool CheckIsPalindrome(std::string str);
int StringToInt(std::string* str_ptr);
std::string IntToStr(int n);
std::string BaseConversionDigitString(std::string* str_ptr, const int b1, const int b2);
int HexadecimalcharacterToInteger(char c);
char DecimalIntegerToHexadecimalCharacter(const int num);
int OrderingNumberOfColumnName(std::string colname);




