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
void ElementsOfProgrammingChapter06Strings_RomanNumberStringToInteger();
void ElementsOfProgrammingChapter06Strings_IntegerToShortestRomanNumberString();
void ElementsOfProgrammingChapter06Strings_MakeIPadressesFromNumber();
void ElementsOfProgrammingChapter06Strings_SinusoidalOrdering();
void ElementsOfProgrammingChapter06Strings_RunlengthEncodingDecoding();
void ElementsOfProgrammingChapter06Strings_RabinKarp();


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

int RomanNumberStringToInteger(const std::string* str_ptr);
std::string IntegerToShortestRomanNumberString(int number);

void ComputePossibleIPadressesFromDigitSequence_Recursive(std::string digit_sequence,
  int n_dots_to_be_set,
  std::string ip,
  std::vector<std::string>* list_ips_ptr);
void ComputePossibleIPadressesFromDigitSequence_Loops(
  const std::string digit_sequence, std::vector<std::string>* list_ips_ptr);
bool IsValid8bitPart(const std::string digit_sequence);

void SinusoidalOrder(std::string* str_ptr);

std::string RunLengthEncoding(std::string* str_ptr, int n_relevant);
std::string RunLengthDecoding(std::string* str_ptr, int n_relevant);
int RunLengthEncoding_Inplace(std::string* str_ptr, int n_relevant);
int RunLengthDecoding_Inplace(std::string* str_ptr, int n_relevant);

int RabinKarp(const std::string* text_ptr, const std::string* search_str_ptr);
unsigned long long RollingHash(const std::string* str_ptr, const unsigned long long max_allowed);
unsigned long long RollingHash(const unsigned long long old_hash,
  const char removed, const char added, const int window_len, const unsigned long long max_allowed);


