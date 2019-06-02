#pragma once

#include <string>
#include <vector>


void ElementsOfProgrammingChapter06Strings();

void ElementsOfProgrammingChapter06Strings_CheckIsPalindromeWord();
void ElementsOfProgrammingChapter06Strings_CheckIsPalindromeText();
void ElementsOfProgrammingChapter06Strings_StringToInt();
void ElementsOfProgrammingChapter06Strings_IntToString();
void ElementsOfProgrammingChapter06Strings_BaseConversionDigitString();
void ElementsOfProgrammingChapter06Strings_OrderingNumberOfSpreadsheetColumn();
void ElementsOfProgrammingChapter06Strings_RemoveAndReplaceLettersOfStringInPlace();
void ElementsOfProgrammingChapter06Strings_ReverseOrderOfWordsInTextInPlace();
void ElementsOfProgrammingChapter06Strings_MnemonicsOfPhoneNumber();
void ElementsOfProgrammingChapter06Strings_LookAndSaySequence();


bool CheckIsPalindromeWord(std::string str);
bool CheckIsPalindromeText(std::string str);

int StringToInt(std::string* str_ptr);
std::string IntToStr(int n);
std::string BaseConversionDigitString(std::string* str_ptr, const int b1, const int b2);
int HexadecimalcharacterToInteger(char c);
char DecimalIntegerToHexadecimalCharacter(const int num);
int OrderingNumberOfColumnName(std::string colname);
void RemoveAndReplaceLettersInPlace(std::string* str_ptr, const int n_relevant_letters);
void ReverseOrderOfWordsInTextInPlace(std::string* str_ptr);

void FindMnemonicsOfPhonenumber_Recursion(std::vector<std::string>* list_mnemonics_ptr,
  const std::string digit_sequence,
  std::string curr_mnemonic);

std::string FindNthElementOfLookAndSaySequence(const int n);




