

#include "pch.h"

#include "ElementsOfProgramming_Chapter06Strings.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>


void ElementsOfProgrammingChapter06Strings() {

  std::cout << "-- Entering ElementsOfProgrammingChapter06Strings " << std::endl;

  //----------------------------------- 

  //--------- Exercise: Check is palindrome word
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Check is palindrome word" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_CheckIsPalindromeWord();

  //--------- Exercise: Check is palindrome text
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Check is palindrome text" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_CheckIsPalindromeText();

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

  //--------- Exercise: Remove and replace letters of string
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: RemoveAndReplaceLettersOfString" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_RemoveAndReplaceLettersOfStringInPlace();
  
  //--------- Exercise: Reverse order of words in text
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: ReverseOrderOfWordsInText" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_ReverseOrderOfWordsInTextInPlace();
  
  //--------- Exercise: Mnemonics of phone number
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: MnemonicsOfPhoneNumber" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_MnemonicsOfPhoneNumber();
  
  //--------- Exercise: LookAndSaySequence
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: LookAndSaySequence" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_LookAndSaySequence();

  return;
}




/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

/*
  Exercise description:

  given a word, check if it is palindromic.
*/
void ElementsOfProgrammingChapter06Strings_CheckIsPalindromeWord() {

  // create two strings
  std::string str1 = "anna";
  std::string str2 = "amna";

  // make the check
  std::cout << "String \"" << str1 << "\" is " << (CheckIsPalindromeWord(str1) ? "" : "not ") << "palindromic" << std::endl;
  std::cout << "String \"" << str2 << "\" is " << (CheckIsPalindromeWord(str2) ? "" : "not ") << "palindromic" << std::endl;

  return;
}

/*
  Exercise description:

  given a string, check if it is palindromic:
  
    considering only the alphanumeric letters, i.e. a-z, A-Z, 0-9
    ignoreing case
*/
void ElementsOfProgrammingChapter06Strings_CheckIsPalindromeText() {
  
  // create two strings
  std::string str1 = "Able was I, ere I saw Elba!";
  std::string str2 = "Ray is Ray";

  // make the check
  std::cout << "String \"" << str1 << "\" is " << (CheckIsPalindromeText(str1) ? "" : "not ") << "palindromic" << std::endl;
  std::cout << "String \"" << str2 << "\" is " << (CheckIsPalindromeText(str2) ? "" : "not ") << "palindromic" << std::endl;

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

/*
  Exercise description:

  Given a string, apply two rules to modify the string

    - remove all b's
    - replace all a's by dd

  Work in-place on the incoming string and assume that it has enough extra space if it gets longer.

*/
void ElementsOfProgrammingChapter06Strings_RemoveAndReplaceLettersOfStringInPlace() {
  
  // setting
  std::string test_str = "dcbaabcdaa";
  const int relevant_letters = test_str.size();
  test_str.resize(relevant_letters + 2);  // to provide enough space
  std::cout << "String example:" << std::endl;
  std::cout << test_str << std::endl;

  // apply the modifications in place
  RemoveAndReplaceLettersInPlace(&test_str, relevant_letters);

  // print result
  std::cout << "After modification:" << std::endl;
  std::cout << test_str << std::endl;

  return;
}

/*
  Exercise description:

  Given a text containing of words and white spaces, reverse the order of the words.
  Work in place.

*/
void ElementsOfProgrammingChapter06Strings_ReverseOrderOfWordsInTextInPlace() {

  // setting
  std::string test_text = "This is the story";
  std::cout << "Text example:" << std::endl;
  std::cout << test_text << std::endl;

  // Reverse order
  ReverseOrderOfWordsInTextInPlace(&test_text);

  // print result
  std::cout << "Reversed order:" << std::endl;
  std::cout << test_text << std::endl;

  return;
}

/*
  Exercise description:

  Given a string of digits (e.g. a phone number), find all 
  mnemomics that this sequence of digits can represent    

*/
void ElementsOfProgrammingChapter06Strings_MnemonicsOfPhoneNumber() {

  // setting 
  //std::string phone_number = "+61424144024";
  //std::string phone_number = "144024";
  std::string phone_number = "7587";

  // Find Mnemonics
  std::vector<std::string> list_mnemonics;
  FindMnemonicsOfPhonenumber_Recursion(&list_mnemonics, phone_number, "");

  // print all found results
  std::cout << "Found mnemonics: " << list_mnemonics.size() << std::endl;
  for (std::string mnemonic : list_mnemonics) {
    std::cout << mnemonic << std::endl;
  }
  std::cout << std::endl;

  return;
}

/*
  Exercise description:

  the look-and-say sequence starts with the integer 1.
  the next element is obtained by going through the digits of
  the old element and replacing all consecutive sequences of equal
  digits by the count and the digit. This is how many people
  would read out the sequence - thus the name 'look and say'.

  1
  11
  21
  1211
  111221
  312211
  13112221
  ..
*/
void ElementsOfProgrammingChapter06Strings_LookAndSaySequence() {

  // setting
  const int n = 7;

  // compute the nth element
  std::string nth_element = FindNthElementOfLookAndSaySequence(n);

  // print the result
  std::cout << "The " << n << "th element of the sequence is:" << std::endl;
  std::cout << nth_element << std::endl;

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
bool CheckIsPalindromeWord(std::string str) {
  for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}


/*
  idea: go from both ends to compare the characters that should be equal

    - skip all letters that are not alphanumeric
    - neglect case sensitivity

  -> O(n)

*/
bool CheckIsPalindromeText(std::string str) {
  for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
    while (i < j && !isalnum(str.at(i))) { ++i; };
    while (i < j && !isalnum(str.at(j))) { --j; };
    if (i < j) {
      const char left = isdigit(str.at(i)) ? str.at(i) : tolower(str.at(i));
      const char rght = isdigit(str.at(j)) ? str.at(j) : tolower(str.at(j));
      if (left != rght) {
        return false;
      }
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


/*
  Two Rules:

    - remove b's
    - replace a's by dd

  Idea: 

    This would be very simply doable in O(n) time, if we could use additional O(n) space.
    If we work in place, however, one needs a clever way to preserver the O(n) complexity.

    The key idea is to do multiple traversals. In the first traversal count how long the
    resulting string will be. In the second traversal, start at the end of the
    relevant letters in the input string and write to the end of the resulting string.

    a) If no a's and b's are present this will obviously work.
    b) If only a's are present, the hardest case is that the input string offers exactly
    as many space as will be needed after replacing a's with double d's. In that case
    the writing from the right will be faster than the reading, but by construction
    it is guaranteed that it can never overtake the reading. If it reaches the reading
    we know that no more a's can occur because we determined the length
    of the resulting string.
    c) If a's and b's are present, the rationale of b) comes to a problem. The writing 
    could overtake the reading if there are still some b's to come. To avoid this
    we have to do a writing that removes the b's first and then follow the logic of b).

*/
void RemoveAndReplaceLettersInPlace(std::string* str_ptr, const int n_relevant_letters) {

  std::string& str = *str_ptr;

  // 1. remove b's (going left to right), also count a's and b's
  int count_a = 0;
  int count_b = 0;
  for (int read_i = 0, write_i = 0; read_i < n_relevant_letters; ++read_i) {
    const char c = str.at(read_i);    
    if (c != 'b') {
      str.at(write_i++) = str.at(read_i);
      if (c == 'a') {
        ++count_a;
      }
    }
    else { // b's are not written
      ++count_b;
    }
  }
  int len_no_bs = n_relevant_letters - count_b;
  int len_result = len_no_bs + count_a;

  // 2. replace a's
  for (int read_i = len_no_bs - 1, write_i = len_result - 1; read_i >= 0; --read_i) {
    const char c = str.at(read_i);
    if (c == 'a') {
      str.at(write_i--) = 'd';
      str.at(write_i--) = 'd';
    }
    else {
      str.at(write_i--) = c;
    }
  }

  return;
}

/*
  idea: 

  using O(n) additional space, it would be easy to copy the words
  from the input to the output string in reverse order in O(n) time.

  using O(1) space, the key insight for an O(n) time algorithm is
  that we do two reversals:

    1. reverse all letters of the whole string, O(n)
    2. go through, identifying words by blank space delimitors, and
    reverse the words, O(2 *n)

    --> O(n) time, O(1) space
*/
void ReverseOrderOfWordsInTextInPlace(std::string* str_ptr) {

  std::string& str = *str_ptr;

  // reverse the string
  std::reverse(str.begin(), str.end());

  // go through to identify words and reverse te words
  for (std::string::iterator it = str.begin(), blank_it = it; it < str.end(); ) {
    while (blank_it < str.end() && *blank_it != ' ') {
      ++blank_it;
    }
    // now word_i is either at the next blank space, or beyond the size of the string    
    std::reverse(it, blank_it);
    if (blank_it < str.end()) {
      ++blank_it; // move to next letter or past-the-end iterator
    }
    it = blank_it;;
  }

  return;
}


/*
  Idea: 

  Use recursion
    
  Note: 0 and 1 remain as they are.
  Note: all non-digit chars remain as they are

  -> this will maximally give 4^n mnemomics , where n is the length of the digit_sequence

  -> space O(4^n)
  -> time O(4^n * n) because each base case does an O(n) operation

*/
void FindMnemonicsOfPhonenumber_Recursion(std::vector<std::string>* list_mnemonics_ptr, 
  const std::string digit_sequence,
  std::string curr_mnemonic
  ) {  
  std::vector<std::string>& list_mnemonics = *list_mnemonics_ptr;

  if (digit_sequence.empty()) {
    list_mnemonics.emplace_back(curr_mnemonic); // O(n): making copy of the resulting mnemonic
    return;
  }

  const std::unordered_map<char, std::unordered_set<char>> keypad = {
    {'2', {'A', 'B', 'C'}},
    {'3', {'D', 'E', 'F'}},
    {'4', {'G', 'H', 'I'}},
    {'5', {'J', 'K', 'L'}},
    {'6', {'M', 'N', 'O'}},
    {'7', {'P', 'Q', 'R', 'S'}},
    {'8', {'T', 'U', 'V'}},
    {'9', {'W', 'X', 'Y', 'Z'}}  
  };

  // go through all possibilites
  const char current_char = digit_sequence.at(0);
  std::unordered_set<char> possible_vals;
  if (keypad.find(current_char) != keypad.end()) {  // if char is a digit of keypad
    possible_vals = keypad.at(current_char);
  }
  else { // otherwise the only possible value is the char itsself
    //possible_vals.emplace(current_char);
    FindMnemonicsOfPhonenumber_Recursion(list_mnemonics_ptr,
      digit_sequence.substr(1, digit_sequence.size() - 1),
      curr_mnemonic);
  }
  for (char c : possible_vals) {
    curr_mnemonic.push_back(c);
    FindMnemonicsOfPhonenumber_Recursion(list_mnemonics_ptr, 
      digit_sequence.substr(1, digit_sequence.size() - 1), 
      curr_mnemonic);
    curr_mnemonic.pop_back();
  }

  return;
}


/*
  idea:

  we need to compute the nth element by computing each element
  of the sequence iteratively from the previous one.

  we have n iterations.
  in each iteration the element can have at most twice the number
  of digits as before (if no two consecutive digits are the same),
  therefore with each iteration we maximally double the digits.
  -> at the end we have an upper bound for the digits of 2^n


  -> the time complexity is bound by O(n * 2^n)

  -> space complexity is bound by O(2^n)
  
 */
std::string FindNthElementOfLookAndSaySequence(const int n) {
  std::string curr_element = "11";
  for (int i = 3; i <= n; ++i) {
    std::string next_element;
    int count = 1;
    for (int k = 0; k < (int)curr_element.size() - 1; ++k) {
      const char c = curr_element.at(k);
      if (curr_element.at(k + 1) == c) {
        ++count;        
      }
      else {
        next_element += std::to_string(count);
        next_element += c;        
        count = 1;
      }
      // since we check the next element the last element itself has to be handled
      if (k == curr_element.size() - 2) {
        next_element += std::to_string(count); // count was already raised or set to 1
        next_element += curr_element.at(k + 1);
      }
    }
    // now we have found the new element
    curr_element = next_element;
  }
  return curr_element;
}