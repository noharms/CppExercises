

#include "pch.h"

#include "ElementsOfProgramming_Chapter06Strings.h"

#include <iostream>


void ElementsOfProgrammingChapter06Strings() {

  std::cout << "-- Entering ElementsOfProgrammingChapter06Strings " << std::endl;

  //----------------------------------- 

  //--------- Exercise: Check is palindrome
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Check is palindrome" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_CheckIsPalindrome();  
  
  //--------- Exercise: String to int
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: String to int" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_StringToInt();
  
  //--------- Exercise: Int to String
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Int to String" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_IntToString();
  
  //--------- Exercise: Base conversion of digit-string
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Base conversion of digit string" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_BaseConversionDigitString();
  
  //--------- Exercise: Convert Spreadsheet column-name to ordering number
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: OrderingNumberOfSpreadsheetColumn" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_OrderingNumberOfSpreadsheetColumn();

  return;
}




/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

/*
  Exercise description:

  given a string, check if it is palindromic.
*/
void ElementsOfProgrammingChapter06Strings_CheckIsPalindrome() {

  // create two strings
  std::string str1 = "anna";
  std::string str2 = "amna";

  // make the check
  std::cout << "String " << str1 << " is " << (CheckIsPalindrome(str1) ? "" : "not ") << "palindromic" << std::endl;
  std::cout << "String " << str2 << " is " << (CheckIsPalindrome(str2) ? "" : "not ") << "palindromic" << std::endl;

  return;
}


/*
  Exercise description:

  given a string (of digits), convert it to an integer
*/
void ElementsOfProgrammingChapter06Strings_StringToInt() {

  // create a string of digits
  std::string mystr = "-12306";
  std::cout << "Convert the strin " << mystr << " to an integer." << std::endl;

  // convert string to integer
  int corresponding_int = StringToInt(&mystr);

  // print integer
  std::cout << "String to int conversion gave " << corresponding_int << std::endl;

  return;
}

/*
  Exercise description: 

  given an integer convert it to a string
*/
void ElementsOfProgrammingChapter06Strings_IntToString() {

  // set an integer
  int my_int = -145052;
  std::cout << "Converting the integer " << my_int << " to a string." << std::endl;

  // Convert
  std::string corresponding_str = IntToStr(my_int);

  // print result
  std::cout << "Int to string conversion gave " << corresponding_str << std::endl;

  return;
}

/*
  Exercise description:

  given a string of digits and a base between 2 and 16 (note digits can thus
  be 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F), and another base,
  convert the string of digits so that it represents the same number but
  in the other base.
*/
void ElementsOfProgrammingChapter06Strings_BaseConversionDigitString() {

  // settings
  //const int b1 = 16;
  //const int b2 = 2;
  //std::string digit_str_b1 = "AB";
  
  const int b1 = 2;
  const int b2 = 16;
  std::string digit_str_b1 = "10101011";  

  // convert the string
  std::string digit_str_b2 = BaseConversionDigitString(&digit_str_b1, b1, b2);

  // print the result
  std::cout << "Digits in base1 " << b1 << ": " << digit_str_b1 << std::endl;
  std::cout << "Digits in base2 " << b2 << ": " << digit_str_b2 << std::endl;

  return;
}

/*
  Exercise description:

  given a string of letters 'A' to 'Z', that are used to name columns
  in a spreadsheet, return the ordering number, e.g.

  'A' = 1
  'B' = 2
  ..
  'Z' = 26
  'AA' = 27
  ..
  'AZ' = 52
  'BA' = 53
  ..
*/
void ElementsOfProgrammingChapter06Strings_OrderingNumberOfSpreadsheetColumn() {

  // setting
  std::string colname = "AAA";

  // compute ordering number
  int col_ordering_number = OrderingNumberOfColumnName(colname);

  // print result
  std::cout << "Column " << colname << " is the " << col_ordering_number << "th column." << std::endl;

  return;
}

/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/


/*
  idea: go from both ends to compare the characters that should be equal

  -> O(n)

*/
bool CheckIsPalindrome(std::string str) {
  for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

/*
  idea:  in ascii table digits come in a sequence and chars
  are converted to their ascii_index in arithmetic expressions

  -> O(n) where n is the length of the string

*/
int StringToInt(std::string* str_ptr) {
  std::string& str = *str_ptr;
  int corresponding_int = 0;
  int i_start = 0;
  if (str[0] == '-') {
    i_start = 1;
  }
  /*for (int i = (int)str.size() - 1; i >= i_start; --i) {
    corresponding_int += (str[i] - '0') * (int)pow(10, (str.size() - 1 - i));    
  }*/
  for (int i = i_start; i < (int)str.size(); ++i) {
    corresponding_int = corresponding_int * 10 + (str[i] - '0');
  }  
  return i_start == 0 ? corresponding_int : (-1)*corresponding_int;
}

/*
  idea: each digit can be easily converted to a char using 
  the ascii table

  note: appending chars to end of string is effective, so
  we do that instead of inserting at front, and simply reverse
  the string afterwards
*/
std::string IntToStr(int n) {
  std::string corresponding_str;
  const int sign = n < 0 ? -1 : 1;
  if (n < 0) {
    n *= -1;   
  }
  while (n) {
    corresponding_str.push_back((char) (n % 10 + '0'));
    n = n / 10;
  }
  if (sign == -1) {
    corresponding_str.push_back('-');
  }
  std::reverse(corresponding_str.begin(), corresponding_str.end());
  return corresponding_str;
}

/*
  idea: 

  we convert the digit-string in base b1 
  to a decimal integer and from the decimal integer
  to a digit-string in base b2

  Note: string to decimal integer is O(n)
        
        integer from base 10 to base b2 is more difficult:
        the integer is maximally b1^n - 1, where n is the original number of digits
        the second loop runs m times, namely until b2^m > integer, i.e. in
        the worst case until b2^m > b1^n
         m = logb2(b1^n) 
           = n * logb2(b1)
        
        -> integer to base b2 is O(n *logb2(b1))

*/
std::string BaseConversionDigitString(std::string* str_ptr, const int b1, const int b2) {
  std::string& str = *str_ptr;
  std::string str_b2;

  // convert digit string to integer
  int integer_base10 = 0;
  int sign = 1;
  if (str[0] == '-') {
    sign *= -1;
  }
  for (int i = 0; i <= (int)str.size() - (sign == 1 ? 1 : 2); ++i) {
    integer_base10 += HexadecimalcharacterToInteger(str[str.size() - 1 - i]) * (int)pow(b1, i);
  }

  // convert decimal integer to digit string wrp to b2
  while (integer_base10) {
    int digit_wrp_b2 = integer_base10 % b2;
    integer_base10 /= b2;    
    char hexadecimal_char = DecimalIntegerToHexadecimalCharacter(digit_wrp_b2);
    str_b2.push_back(hexadecimal_char);
  }
  if (sign == -1) {
    str_b2.push_back('-');
  }
  std::reverse(str_b2.begin(), str_b2.end());

  return str_b2;
}

/*
  Helper: convert character that represents a hexadecimal digit to decimal integer
*/
int HexadecimalcharacterToInteger(char c) {  
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  else if (c >= 'A' && c <= 'E') {
    return 10 + c - 'A';
  }
  else if (c >= 'a' && c <= 'e') {
    return 10 + c - 'a';
  }
  else {
    // error .. should not reach here
    return -1;
  }
}

/*
  Helper: convert decimal integer between 0 and 15 
          to a char that represents hexadecimal digit
*/
char DecimalIntegerToHexadecimalCharacter(const int num) {
  if (num >= 0 && num < 10) {
    return (char)(num + '0');
  }
  else if (num >= 10 && num < 16) {
    return (char)(num - 10 + 'A');
  }
  else {
    // error .. should not reach here
    return 'X';
  }
}


/*
  idea: 
  The spreadsheet ordering can be seen as a positional system
  without a  0.

  AAB = 1 * 26^2 + 1 * 26^1 + 2 * 26^0
      = 676 + 26 + 2
      = 704

  Note: for simple enumerations the lack of a 0 is no
  problem. A numeral system only needs the 0 to allow
  for simple prescriptions to define addition and multiplication.

*/
int OrderingNumberOfColumnName(std::string colname) {
  int ordering_num = 0;
  for (int i = 0; i < (int)colname.size(); ++i) {
    ordering_num *= 26;
    ordering_num += colname[i] - 'A' + 1;
  }
  return ordering_num;
}