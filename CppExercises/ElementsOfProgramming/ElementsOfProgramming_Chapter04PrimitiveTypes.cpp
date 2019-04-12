

#include "pch.h"

#include "ElementsOfProgramming_Chapter04PrimitiveTypes.h"

#include <iostream>
#include <time.h>
#include <stack>

void ElementsOfProgrammingChapter04PrimitiveTypes() {
  
  std::cout << "-- Entering ElementsOfProgrammingChapter04PrimitiveTypes " << std::endl;

  //--------- Exercise: Unset Lowermost-set-bit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Unset Lowermost-set-bit: " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLSB();
  
  //--------- Exercise: Compute Parity - using UnsetLSB
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Compute parity " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLSB();

  return;
}


/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity. 

    -> set the lowermost-set-bit to 0 

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLSB() {

  srand((unsigned char) time(NULL));

  // choose an integer at random
  const int kMaxRand = (int) pow(10, 8);
  int number = rand() % kMaxRand;
  std::cout << "Random number: " << number << std::endl;
  
  // print the bits of the number
  PrintIntegerAsBitField(number);

  // unset the lowermost set bit
  number = UnsetLSB(number);

  // Print the bits of the modified number
  PrintIntegerAsBitField(number);

  return;
}



/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity.

    -> compute the parity of the bit-field

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLSB() {

  srand((unsigned char)time(NULL));

  // choose an integer at random
  const int kMaxRand = (int)pow(10, 8);
  int number = rand() % kMaxRand;
  std::cout << "Random number: " << number << std::endl;

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  bool parity = ComputeParityUsingUnsetLSB(number);

  // output
  std::cout << "-> found parity " << parity << " (using UnsetLSB algorithm) " << std::endl;
  
  return;

}

/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

/**
    Set the least significant bit of an integer from 1 to 0
*/
int UnsetLSB(int num) {  
  return num & (num - 1);
}


/**
    this algorithm is O(k), where k is the number of bits set
*/
bool ComputeParityUsingUnsetLSB(int num) {

  bool parity = 0;

  while (num) {
    //parity = parity == 0 ? 1 : 0;  // equivalent to next line
    parity = parity ^ 1;
    num = UnsetLSB(num);
  }

  return parity;
}



/**
    Print integer in base 2
*/
void PrintIntegerAsBitField(int num) {
  std::cout << "Bitfield of " << num << " : ";
  std::stack<bool> bit_stack;
  while (num) {
    bit_stack.push(num & 1);
    num >>= 1;
  }
  while (!bit_stack.empty()) {
    std::cout << bit_stack.top();
    bit_stack.pop();
  }
  std::cout << std::endl;
  return;
}