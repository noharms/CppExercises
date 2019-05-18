

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
  std::string mystr = "-149410";
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
  for (int i = str.size() - 1; i >= i_start; --i) {
    corresponding_int += (str[i] - '0') * (int)pow(10, i);
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