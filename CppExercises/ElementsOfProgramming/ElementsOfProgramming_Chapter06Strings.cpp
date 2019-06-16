

#include "pch.h"

#include "ElementsOfProgramming_Chapter06Strings.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>


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

  //--------- Exercise: RomanNumberStringToInteger
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: RomanNumberStringToInteger" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_RomanNumberStringToInteger();

  //--------- Exercise: IntegerToShortestRomanNumberString
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: IntegerToShortestRomanNumberString" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_IntegerToShortestRomanNumberString();
  
  //--------- Exercise: MakeIPadressesFromNumber
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: MakeIPadressesFromNumber" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_MakeIPadressesFromNumber();

  //--------- Exercise: SinusoidalOrdering
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: SinusoidalOrdering" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_SinusoidalOrdering();

  //--------- Exercise: RunlengthEncodingDecoding
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: RunlengthEncodingDecoding" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_RunlengthEncodingDecoding();
  
  //--------- Exercise: RabinKarp
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: RabinKarp" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter06Strings_RabinKarp();

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

/*
  Exercise description:

  given a string that represents a Roman number, convert it to an integer.

  a Roman number consists of the letters 

  I, V, X, L, C, D, M   = 1, 5, 10, 50, 100, 500, 1000

  they have to appear in monotone descending order, with the exception that

  IV, IX, XL, XC, CD, CM  may appear (but never togeter, e.g. not IXL)

*/
void ElementsOfProgrammingChapter06Strings_RomanNumberStringToInteger() {
  
  // setting
  std::string romannumber_str = "MMMCDLXXXIV";

  // compute the corresponding integer
  int number = RomanNumberStringToInteger(&romannumber_str);

  // print the result
  std::cout << "The Roman number " << romannumber_str << " corresponds to:" << std::endl;
  std::cout << number << std::endl;

  return;
}

/*
  Exercise description:

  given an integer, find the shortest roman number string of the same value

  note: roman number strings are not unique !

  e.g. 4 can be written as IIII and as IV.
*/
void ElementsOfProgrammingChapter06Strings_IntegerToShortestRomanNumberString() {

  // setting
  int number = 3484;

  // compute the corresponding integer
  std::string romannumber_str = IntegerToShortestRomanNumberString(number);

  // print the result
  std::cout << "The number " << number << " is shortest written in roman literals as:" << std::endl;
  std::cout << romannumber_str << std::endl;

  return;
}

/*
  Exercise description: 

  given a string of a digit-sequence that was formerly an ip-adresses but lost its dots,
  find all possible ip-adresses that this sequence could have been before.

  Note: an ip adress is a 32-bit number, which is usually represented as
        4 8-bit numbers separated by a dot. Each of the 4 8-bit numbers can
        be in the range 0..255
*/
void ElementsOfProgrammingChapter06Strings_MakeIPadressesFromNumber() {

  // setting
  const std::string ipadress_withoutdots = "25525511";

  // compute all possible ip-adresses
  std::vector<std::string> list_ipadresses;  
  ComputePossibleIPadressesFromDigitSequence_Loops(ipadress_withoutdots, &list_ipadresses);

  // Alternative algorithm using recursion
  //std::string ipadress;
  //ComputePossibleIPadressesFromDigitSequence_Recursive(ipadress_withoutdots, 3, ipadress, &list_ipadresses);

  // print the result
  std::cout << "The digit sequence " << ipadress_withoutdots << " could be one of the following ip-adresses" << std::endl;
  for (auto it = list_ipadresses.begin(); it != list_ipadresses.end(); ++it) {
    std::cout << (*it) << std::endl;
  }
  std::cout << std::endl;

  return;
}


/*
  Exercise description: 

  The sinusoidal ordering is heuristically given by distributing the string
  over three ranks and then going left to right through the 1st, then 2nd, and then 3rd rank
                           e          blank            l
  "Hello World!"  -->   H    l     o         W      r    d
                                l                o           !

                 -->  "e lHloWrdlo!"

  Given a string, compute its sinusoidal ordering.
  
*/
void ElementsOfProgrammingChapter06Strings_SinusoidalOrdering() {

  // setting
  std::string str = "Hello World!";
  std::string str_cpy = str;

  // compute sinusoidal ordering
  SinusoidalOrder(&str);

  // print the result
  std::cout << str_cpy << " reads in sinusoidal order:" << std::endl;
  std::cout << str << std::endl;

  return;
}

/*
  Exercise description:

  Run-Length-encoding (RLE) of a string of small letters means to write
  the number of consecutive appearances of the same letter followed
  by the letter.

  Given a string consisting of small letters, find the Runlength-encoded string.
  Given a RLE-string, find the decoded string.

*/
void ElementsOfProgrammingChapter06Strings_RunlengthEncodingDecoding() {

  // setting
  std::string str = "abcdefghijklmnoffffffffffggg";
  int n_relevant = str.size();
  std::cout << str << " is going to be RLE encoded." << std::endl;
  
  // Encoding/Decoding --- O(n) space 
  std::cout << "O(n) space algorithm:" << std::endl;
  str = RunLengthEncoding(&str, n_relevant);
  std::cout << str << " (after encoding)" << std::endl;
  str = RunLengthDecoding(&str, str.size());
  std::cout << str << " (after decoding)" << std::endl;
  
  // Encoding/Decoding --- O(1) space
  std::cout << "O(1) space algorithm:" << std::endl;
  for (int i = 0; i < 10; ++i) {  // to have enough space allocated for in-place algorithm
    str += " ";
  }
  int n_relevant_encoded = RunLengthEncoding_Inplace(&str, n_relevant);
  std::cout << str << " (after encoding)" << std::endl;
  int n_relevant_decoded = RunLengthDecoding_Inplace(&str, n_relevant_encoded);
  std::cout << str << " (after decoding)" << std::endl;
  

  // print

  return;
}

/*
  Exercise descipription:

  implement the RabinKarp search algorithm, which allows to search a
  string in another string in average O(n) time.

*/
void ElementsOfProgrammingChapter06Strings_RabinKarp() {

  // setting
  std::string text = "In computer science, the Rabin–Karp algorithm or Karp–Rabin algorithm is a string-searching algorithm created by Richard M. Karp and Michael O. Rabin (1987) that uses hashing to find any one of a set of pattern strings in a text. For text of length n and p patterns of combined length m, its average and best case running time is O(n+m) in space O(p), but its worst-case time is O(nm). In contrast, the Aho–Corasick string-matching algorithm has asymptotic worst-time complexity O(n+m) in space O(m). A practical application of the algorithm is detecting plagiarism. Given source material, the algorithm can rapidly search through a paper for instances of sentences from the source material, ignoring details such as case and punctuation. Because of the abundance of the sought strings, single - string searching algorithms are impractical.";
  std::string search_str = "imprac";

  // find substring
  int position = RabinKarp(&text, &search_str);

  // result
  if (position >= 0) {
    std::cout << "RabinKarp found the string \"";
    std::cout << search_str << " at position: " << position << std::endl;
    std::cout << "The text at this position is " << text.substr(position, 10) << std::endl;
  }
  else {
    std::cout << "RabinKarp did not find the search string." << std::endl;
  }  

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


/*
  idea: 

  without the exceptions it would be super simple: just add up
  the mapped value of the roman literals.

  due to the possible exceptions, we have to add a check 
  whether the new element is larger than the previous, in
  which case a special handling is required
*/
int RomanNumberStringToInteger(const std::string* str_ptr) {
  const std::string& str = *str_ptr;
  int number = 0;
  const std::unordered_map<char, int> roman2int = {
    { 'I', 1},
    { 'V', 5},
    { 'X', 10},
    { 'L', 50},
    { 'C', 100},
    { 'D', 500},
    { 'M', 1000}
  };
  int val_prev = std::numeric_limits<int>::max();
  for (char c : str) {
    int val_curr = roman2int.at(c);
    number += val_curr;
    if (val_curr > val_prev) {
      number -= 2 * val_prev;      
    }
    val_prev = val_curr;
  }
  return number;
}

/*
  idea:

  we need to iteratively check if the largest unchecked roman literal
  fits again into the number. starting with M going down to I.

  the restriction that we need to find the shortest representation means,
  we have to use the exceptions CM, CD, XC, XL, IX, IV. so basically,
  we just have to enhance the list of possible roman literals by
  these exceptions in order to check after M = 1000 if CM = 900 is contained
  instead of directly proceeding with D = 500.
*/
std::string IntegerToShortestRomanNumberString(int number) {

  const std::vector<std::pair<int, std::string>> int2romanliterals = {
    { 1000, "M"},
    {  900, "CM"},
    {  500, "D"},
    {  400, "CD"},
    {  100, "C"},
    {   90, "XC"},
    {   50, "L"},
    {   40, "XL"},
    {   10, "X"},
    {    9, "IX"},
    {    5, "V"},
    {    4, "IV"},
    {    1, "I"}
  };

  std::vector<std::pair<int, std::string>>::const_iterator it = int2romanliterals.begin();
  std::string romannumber_str;
  while (number) {
    int curr_val = (*it).first;
    if (number >= curr_val) {
      number -= curr_val;
      romannumber_str += (*it).second;
    }
    else {
      ++it;
    }
  }

  return romannumber_str;
}

/*
  idea: 

  the first idea to compute all possible settings for the dots, is to go recursive.

  we can be a bit more efficient by excluding configurations in which one of 
  the 4 8-bit numbers is > 255.

  Note: not sure if ip adresses with less than three points exist, e.g. a single 42
        might also be a valid ip adress. these cannot be handled by this algorithm
        because it will be called with 3 dots to be set initially.
*/
void ComputePossibleIPadressesFromDigitSequence_Recursive(std::string digit_sequence,
  int n_dots_to_be_set,
  std::string ip,
  std::vector<std::string>* list_ips_ptr) {
  std::vector<std::string>& list_ips = *list_ips_ptr;
  // 1. for every dot to be set there needs to be at least one digit
  // 2. for every dot to be set there cannot be more than three additional digits
  int n_digits = digit_sequence.size();
  if ((n_digits < n_dots_to_be_set + 1) ||
    (n_digits > 3 + n_dots_to_be_set * 3)) {
    return;
  }
  // base case
  if (n_dots_to_be_set == 0) {
    int num = stoi(digit_sequence);
    if (num >= 0 && num < 256) {
      ip += digit_sequence;
      list_ips.emplace_back(ip);
    }
    else {
      // else: this digit sequence cannot be part of a valid ip adress
    }
    return;
  }
  int n_possible = n_digits >= 3 ? 3 : n_digits;
  for (int i = 0; i < n_possible; ++i) {
    std::string str_8bit = digit_sequence.substr(0, i + 1);
    int num_8bit = stoi(str_8bit);
    if (num_8bit < 256) {
      ip += str_8bit;
      ip += '.';
      ComputePossibleIPadressesFromDigitSequence_Recursive(digit_sequence.substr(i + 1, n_digits),
        n_dots_to_be_set - 1,
        ip,
        list_ips_ptr);
      ip = ip.substr(0, ip.size() - str_8bit.size() - 1);
    }    
  }
  return;
}

/*
  We can avoid recursion because we know that there are at maximum 3 possible values
  for each of the 4 8bit parts. Since the length of the 4th 8bit number is fixed,
  once the other three are fixed, we do have in total 3*3*3 = 27 possibilites.
  These can be traversed by three nested loops.

  -> time complexity: O(1) because always at maximum 27*O(1) operations
     assuming the input length is constant, or more precisely bounded to be <= 12.

 */
void ComputePossibleIPadressesFromDigitSequence_Loops(
  const std::string digit_sequence, std::vector<std::string>* list_ips_ptr) {
  const int n_digits = digit_sequence.size();
  for (int i = 1; i <= 3 && i < n_digits; ++i) {
    std::string first_8bit = digit_sequence.substr(0, i);
    if (IsValid8bitPart(first_8bit)) {
      for (int j = 1; j <= 3 && (i + j) < n_digits; ++j) {
        std::string second_8bit = digit_sequence.substr(i, j);
        if (IsValid8bitPart(second_8bit)) {
          for (int k = 1; k <= 3 && (i + j + k) < n_digits; ++k) {
            std::string third_8bit = digit_sequence.substr(i + j, k);
            std::string fourth_8bit = digit_sequence.substr(i + j + k, n_digits - (i + j + k));
            if (IsValid8bitPart(third_8bit) && IsValid8bitPart(fourth_8bit)) {
              std::string ip = first_8bit + "." + second_8bit + "." + third_8bit + "." + fourth_8bit;
              list_ips_ptr->emplace_back(ip);
            }
          }
        }
      }      
    }
  }
  return;
}

bool IsValid8bitPart(const std::string digit_sequence) {
  if (digit_sequence.front() == '0' && digit_sequence.size() > 1) {
    return false; // 0 is allowed, but 01, 001, and so on not
  }
  int num = stoi(digit_sequence);
  return (num >= 0 && num < 256) ? true : false;
}


/*
  Idea:

    If we use O(n) space, it is easy to devise an O(n) time algorithm:
    starting at index 1, go through the str in steps of 4 to get the top rank
    elements and append them to the new string.
    starting at index 0, go through the str in steps of 2 to get the middle rank.
    starting at index 3, go through the str in streps of 4 to get the bottom rank.

    -> would be O(n) time and O(n) space

  Interesting Alternative:

    Seeing the reordering as a permutation  (also O(n) and O(n))

    Motivated by the fact, that the reordering of the string can be viewed as
    applying a permutation to the original string, one might think that
    there is an O(n) time algorithm that works in place 
    (given an array of elements and an array that represents the permutation
    one can use the permutation-array to store for each element 
    the information whether it has been set to its new place or not and
    thus break free from cyclic permutations).

    Thus if we grant ourselves O(n) to store the info whether an element has been
    permuted already we can work as we would for a permutation!

    Instead of storing the permuation as an array, we compute the new index
    for each element on the fly and permute.

    -> O(n) space to avoid cyclic permutation, O(n) time

*/
void SinusoidalOrder(std::string* str_ptr) {
  std::string& str = *str_ptr;

  const int n_elem = str.size();
  const int n_per_block = 4;
  const int n_blocks = n_elem / n_per_block;
  const int n_in_unfull_block = n_elem % n_per_block; // at the end of the str, maybe an partly filled block
  const int n_elem_1strank = n_blocks + ((n_in_unfull_block >= 2) ? 1 : 0);
  const int n_elem_2ndrank = 2 * n_blocks + ((n_in_unfull_block >= 1) ? 1 : 0 + (n_in_unfull_block >= 3) ? 1 : 0);
  const int n_elem_3rdrank = n_blocks + ((n_in_unfull_block >= 3) ? 1 : 0);

  int source_i = 0;
  int target_i;
  char next_char_to_be_set = str.at(source_i);
  std::vector<bool> perm_done(n_elem, false);
  int n_perms_done_from_left = 0;
  for (int i = 0; i < n_elem; ++i) {
    int n_blocks_before_source_i = source_i / n_per_block;
    if (source_i % n_per_block == 0) { // becomes a 2nd rank element
      target_i = n_elem_1strank + 2 * n_blocks_before_source_i;
    }
    else if (source_i % n_per_block == 1) { // becomes a 1st rank element
      target_i = n_blocks_before_source_i;
    }
    else if (source_i % n_per_block == 2) { // becomes a 2nd rank element
      target_i = n_elem_1strank + 2 * n_blocks_before_source_i + 1;
    }
    else if (source_i % n_per_block == 3) { // becomes a 3rd rank element
      target_i = n_elem_1strank + n_elem_2ndrank + n_blocks_before_source_i;
    }
    char target_old_char = str.at(target_i);
    str.at(target_i) = next_char_to_be_set;
    perm_done.at(source_i) = true;
    // prepare for next round
    if (perm_done.at(target_i) == false) {
      next_char_to_be_set = target_old_char;
      source_i = target_i;
    }
    else { // start new cycle
      if (i == n_elem - 1) {
        break;
      }
      while (perm_done.at(n_perms_done_from_left)) { ++n_perms_done_from_left; }      
      source_i = n_perms_done_from_left;
      next_char_to_be_set = str.at(source_i);
    }    
  }

  return;
}

/*
  idea: with O(n) space it is easy

  go through the string until finding a new character counting the old

*/
std::string RunLengthEncoding(std::string* str_ptr, int n_relevant) {
  std::string& str = *str_ptr;
  std::string str_encoded;   
  int count;
  for (int i = 0; i < n_relevant - 1; i += count) {
    count = 1;
    while (i + count < n_relevant && str.at(i + count) == str.at(i)) {
      ++count;
    }
    str_encoded += std::to_string(count);
    str_encoded += str.at(i);    
  }
  if (str.at(n_relevant - 1) != str.at(n_relevant - 2)) {
    str_encoded += '1' + str.at(n_relevant - 1);
  }
  return str_encoded;
}

/*
  idea: with O(n) space it is easy

  just go through the encoded string, identify the numbers and the next letter
  and append the letter a number of times to the resulting string

*/
std::string RunLengthDecoding(std::string* str_ptr, int n_relevant) {
  std::string& str = *str_ptr;
  std::string str_decoded;
  for (int i = 0; i < n_relevant; ++i) {
    std::string count_as_str;
    count_as_str += str.at(i);  // note: the very first char in the string must be a digit
    if (isdigit(str.at(i + 1))) { // note: the last char in the string must be a letter
      count_as_str += str.at(++i);
    }
    int count = stoi(count_as_str);
    char letter = str.at(++i);
    while (count) {
      str_decoded += letter;
      --count;
    }
  }
  return str_decoded;
}


/*
  Idea for in-place:

  working in place, we have the difficulty that the result can be shorter
  and can be longer than the input (e.g. "abc" becomes "1a1b1c").

  -> even if we computed the length of the result, we could not
     start to fill the result backwards from there because we might
     overwrite values that we need.

  => we can always start at the back, and then shift the result to the
     beginning

  Note: we assume that the given string is long enough for the result
*/
int RunLengthEncoding_Inplace(std::string* str_ptr, int n_relevant) {
  std::string& str = *str_ptr;

  // 0. count how many single letters there are, in order to know how large result becomes
  int count_singles = 0;
  for (int j = 1; j < n_relevant - 1; ++j) {
    if (str.at(j + 1) != str.at(j) && str.at(j - 1) != str.at(j)) {
      ++count_singles;
    }
  }
  if (str.at(0) != str.at(1)) {
    ++count_singles;
  }
  if (str.at(n_relevant - 1) != str.at(n_relevant - 2)) {
    ++count_singles;
  }

  // 1. replace sequences >= 2 (in this step result becomes shorter or stays equal size)
  int n_result = 0;
  int write_i = 0;
  int read_i = 0;
  int n_equal = 1;
  while (read_i < n_relevant - 1) {
    if (str.at(read_i + 1) == str.at(read_i)) {
      ++n_equal;
    }
    else {
      if (n_equal > 1) {
        std::string count_as_str = std::to_string(n_equal);
        str.replace(write_i, count_as_str.size(), count_as_str);
        write_i += count_as_str.size();
        n_equal = 1;
      }
      // write the letter
      str.at(write_i++) = str.at(read_i);
    }
    ++read_i;
  }
  // take care of last character
  if (n_equal > 1) {
    std::string count_as_str = std::to_string(n_equal);
    str.replace(write_i, count_as_str.size(), count_as_str);
    write_i += count_as_str.size();
  }
  // write the letter
  str.at(write_i) = str.at(read_i);

  // fill up the part after the result with blanks
  for (int j = write_i + 1; j < (int)str.size(); ++j) {
    str.at(j) = ' ';
  }

  // 2. encode the single letters (in this step result becomes larger),
  //    -> traverse backwards, startin at length of result
  read_i = write_i;
  int n_relevant_output = read_i + count_singles + 1;
  if ((int)str.size() < n_relevant_output) {
    // ERROR
    std::cout << "For inplace algorithm you need to provide long enough string." << std::endl;
    str = "error";
    return 0;
  }
  write_i = n_relevant_output - 1;
  while (read_i >= 0) {
    str.at(write_i--) = str.at(read_i--); // the letter    
    if (read_i >= 0 && isdigit(str.at(read_i))) {
      while (isdigit(str.at(read_i))) {
        str.at(write_i--) = str.at(read_i--);
      }
    }
    else { // if no digit is left of the letter, it is a single letter
      str.at(write_i--) = '1';
    }
  }

  return n_relevant_output;
}

int RunLengthDecoding_Inplace(std::string* str_ptr, int n_relevant) {
  std::string& str = *str_ptr;

  // 0. count the output length
  int n_result = 0;
  for (int i = 0; i < n_relevant; ++i) {
    std::string count_as_str;
    count_as_str += str.at(i);
    while (i + 1 < n_relevant && isdigit(str.at(i + 1))) {
      count_as_str += str.at(++i);
    }
    // note: at this point the next char is a letter
    n_result += stoi(count_as_str);
    ++i; // now i as at the letter. with the loop increment it will go to next digit
  }

  // 1. do the compression
  int write_i = 0;
  for (int read_i = 0; read_i < n_relevant; ++read_i) {
    std::string count_as_str;
    count_as_str += str.at(read_i);
    while (read_i + 1 < n_relevant && isdigit(str.at(read_i + 1))) {
      count_as_str += str.at(++read_i);
    }
    // note: at this point read_i is at the last digit of current number
    int count = stoi(count_as_str);
    if (count > 1) {
      str.replace(write_i, count_as_str.size(), count_as_str);
      write_i += count_as_str.size();
    }
    // write the letter
    str.at(write_i++) = str.at(++read_i);
  }  

  // 2. do the expansion
  int n_after_compression = write_i; // write_i is one beyond the last written letter
  write_i = n_result - 1;
  for (int read_i = n_after_compression - 1; read_i >= 0; --read_i) {
    char letter = str.at(read_i);
    if (read_i - 1 >= 0 && isdigit(str.at(read_i - 1))) { // if a number comes left, we still need to decode
      std::string count_as_str;
      while (read_i - 1 >= 0 && isdigit(str.at(read_i - 1))) {
        count_as_str += str.at(--read_i);
      }
      // note: at this point read_i is at the leftmost digit of current number
      std::reverse(count_as_str.begin(), count_as_str.end());
      int count = stoi(count_as_str);
      for (int k = 0; k < count; ++k) {
        str.at(write_i--) = letter;
      }
      // note: read_i will be decremented to reach the next letter by the loop
    }
    else { // if left of the letter comes another letter, the current was already decoded
      str.at(write_i--) = letter;
    }
  }

  // 3. fill up the remaining part
  for (int i = n_result; i < (int)str.size(); ++i) {
    str.at(i) = ' ';
  }

  return n_result;
}

/*
  idea: 

  RabinKarp is closely related to the brute force algorithm.

  iterate through the text and check if the string that is build starting
  at the current letter matches the search-string.

  naively implemented, this could result in O(n*m) runtime, e.g

  text = aaaaaa
  search = aaab
  --> will make n/2 checks, each of which takes m comparisons

  the key-insight to improve this is to use a rolling hash-function of a string,
  i.e. one which is additive in the included chars.

*/
int RabinKarp(const std::string* text_ptr, const std::string* search_str_ptr) {
  const std::string& text = *text_ptr;
  const std::string& search_str = *search_str_ptr;

  int position = -1;
  unsigned long long hash_search_str = RollingHash(search_str_ptr, std::numeric_limits<unsigned long long>::max());
  int search_str_len = search_str.size();    

  // check if we have a match already at position 0
  std::string initial_str_in_text = text.substr(0, search_str_len);
  unsigned long long hash_oldcandidate = RollingHash(&initial_str_in_text, std::numeric_limits<unsigned long long>::max());
  if (hash_oldcandidate == hash_search_str) {
    if (search_str.compare(text.substr(0, search_str_len)) == 0) {
      return 0;  // position 0 gives a match
    }
  }

  // go through all other starting-positions for the substring in the text
  for (int i = 1; i < text.size() - search_str_len; ++i) {
    char removed = text.at(i - 1);
    char added = text.at(i + search_str_len - 1);
    unsigned long long hash_newcandidate = RollingHash(hash_oldcandidate, removed, added, search_str_len, std::numeric_limits<unsigned long long>::max());
    if (hash_newcandidate == hash_search_str) {      
      if (search_str.compare(text.substr(i, search_str_len)) == 0) {
        position = i;
        break;
      }
    }
    hash_oldcandidate = hash_newcandidate;
  }

  return position;
}

/*
  idea: 

  the window moves left-to-right through the char-array

  -> the leftmost char is removed, i.e. it must be the one at the highest power
  -> the rightmost char is the newest, i.e. it was just added at order 0
*/
unsigned long long RollingHash(const std::string* str_ptr, const unsigned long long max_allowed) {
  const std::string& str = *str_ptr;
  const int kMult = 53;
  unsigned long long hash_code = 0;
  for (int i = 0; i < (int)str.size(); ++i) {
    char c = str.at(i);
    hash_code = hash_code * kMult + c;
  }
  return hash_code % max_allowed;
}

unsigned long long RollingHash(const unsigned long long old_hash,
  const char removed, const char added, const int window_len, const unsigned long long max_allowed) {
  const int kMult = 53;
  const unsigned long long val_to_remove = pow(kMult, window_len - 1) * removed;
  const unsigned long long new_hash = (old_hash - val_to_remove) * kMult + added;
  return new_hash % max_allowed;
}