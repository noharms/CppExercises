

#include "pch.h"

#include "ElementsOfProgramming_Chapter04PrimitiveTypes.h"

#include <iostream>
#include <time.h>
#include <stack>
#include <unordered_map>
#include <random>
#include <vector>

void ElementsOfProgrammingChapter04PrimitiveTypes() {
  
  std::cout << "-- Entering ElementsOfProgrammingChapter04PrimitiveTypes " << std::endl;


  // creating larger random numbers than simple rand()
  std::random_device rd;   // non-deterministic generator
  std::mt19937 gen(rd());  // to seed mersenne twister.  
  std::uniform_int_distribution<> dist(1, std::numeric_limits<int>::max());
  unsigned int  number = dist(gen);
  std::cout << "Random number: " << number << std::endl;

  //--------- Exercise: Unset Lowermost-set-bit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Unset Lowermost-set-bit: " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLowestSetBit(number);
  

  //--------- Exercise: Compute Parity - using UnsetLowestSetBit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Compute parity: basic " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityPerDefinition(number);

  //--------- Exercise: Compute Parity - using UnsetLowestSetBit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Compute parity using UnsetLowestSetBit " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLowestSetBit(number);
  
  //--------- Exercise: Compute Parity - using lookup table
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Compute parity using lookup table " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLookupTable(number);
  
  //--------- Exercise: Compute Parity - using divide and conquer
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Compute parity using divide and conquer " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingDivideAndConquer(number);

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
void ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLowestSetBit(unsigned int number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // unset the lowermost set bit
  number = UnsetLowestSetBit(number);

  // Print the bits of the modified number
  PrintIntegerAsBitField(number);

  return;
}

/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity.

    -> compute the parity of the bit-field

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityPerDefinition(unsigned int number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  bool parity = ComputeParityPerDefinition(number);

  // output
  std::cout << "-> found parity " << parity << " (using XOR of single bits) " << std::endl;

  return;

}


/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity.

    -> compute the parity of the bit-field

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLowestSetBit(unsigned int number) {
  
  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  bool parity = ComputeParityUsingUnsetLowestSetBit(number);

  // output
  std::cout << "-> found parity " << parity << " (using UnsetLowestSetBit algorithm) " << std::endl;
  
  return;

}

/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity.

    -> compute the parity of the bit-field

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLookupTable(unsigned int number) {
  
  // debugging
  // std::cout << std::numeric_limits<int>::max() << "--> ACHTUNG." << std::endl;
  // std::cout << 0xFFFFFFFF << "--> ACHTUNG." << std::endl;
  
  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  bool parity = ComputeParityUsingLookUpTable(number);

  // output
  std::cout << "-> found parity " << parity << " (using LookUpTable algorithm) " << std::endl;

  return;
}

/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity.

    -> compute the parity of the bit-field

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingDivideAndConquer(unsigned int number) {
  
  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  bool parity = ComputeParityUsingDivideAndConquer(number, sizeof(unsigned int)*8);

  // output
  std::cout << "-> found parity " << parity << " (using DivideAndConquer algorithm) " << std::endl;

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
int UnsetLowestSetBit(unsigned int  num) {
  return num & (num - 1);
}

/*
    The definition of the parity is the XOR of all single bits !

    -> read the bit-field bit-by-bit and shifting away the read ones until empty
*/
bool ComputeParityPerDefinition(unsigned int num) {  
  bool parity = 0;
  while (num) {
    if (num & ((unsigned int) 0x1)) {
      parity ^= (unsigned int) 0x1 ;
    }
    num >>= 1;
  }
  return parity;
}

/**
    this algorithm is O(k), where k is the number of bits set
*/
bool ComputeParityUsingUnsetLowestSetBit(unsigned int  num) {

  bool parity = 0;

  while (num) {
    //parity = parity == 0 ? 1 : 0;  // equivalent to next line
    parity = parity ^ 1;
    num = UnsetLowestSetBit(num);
  }

  return parity;
}


/*
    this algorithm is O(1) in time, but requires O(2^16) space

    -> note: obviously, this makes only sense if a lot of numbers shall be computed..
*/
bool ComputeParityUsingLookUpTable(unsigned int num) {

  bool parity = 0;

  // create a lookup table for the parities of 16-bit-long bitfields
  // 
  // --> store numbers from 0 to 2^16
  // 
  // Memory requirements:  2^16 ~ 60k 
  // --> 60k * sizeof(int) = 60k * 4 Byte = 240kByte
  // --> a pair in the lookup table will need more than the 4Byte, but this gives an idea 
  // --> We will have no problem on a standard desktop machine (8G of RAM, usually 8Mb stack mem)
  //std::unordered_map<int, bool> lookup_table;  
  const int kBytesCoveredInLookUpTable = 2;
  const int kBitsCoveredInLookUpTable = kBytesCoveredInLookUpTable * 8;
  std::vector<int> lookup_table;
  const int kEntries = (int)pow(2, kBitsCoveredInLookUpTable);
  lookup_table.reserve(kEntries);
  for (int i = 0; i < kEntries; ++i) {
    //lookup_table.emplace(i, ComputeParityUsingUnsetLowestSetBit(i));
    lookup_table.emplace_back(ComputeParityUsingUnsetLowestSetBit(i));
  }

  // cut the number into 16-bit-long pieces, i.e. 2byte long pieces
  size_t size_of_int_this_machine = sizeof(unsigned int); // expecting 2, 4 or 8
  if (size_of_int_this_machine != 4) {
    std::cout << "Limited the algorithm to 64-bit systems. Aborting because int=";
    std::cout << size_of_int_this_machine << "." << std::endl;
    return 0;
  }
  else {
    const int mask_bytes0and1 = 0x0000FFFF;
    const int mask_bytes2and3 = 0xFFFF0000;
    int bytes0and1 = num & mask_bytes0and1;
    int bytes2and3 = (num & mask_bytes2and3) >> 16;
    PrintIntegerAsBitField(bytes0and1);
    PrintIntegerAsBitField(bytes2and3);
    parity = lookup_table.at(bytes0and1) ^ lookup_table.at(bytes2and3);
  }

  return parity;
}

/*
  the idea is that parity of a bitfield is the XOR of the bitfield
  
    parity(abcd) = XOR(abcd)

  and that XOR is associative, i.e. 

    XOR( abcd ) = XOR(ab) XOR XOR(cd)

*/
bool ComputeParityUsingDivideAndConquer(unsigned int num, int n_bits_considered) {

  bool parity = 0;

  if (n_bits_considered == 1) { // base case
    return parity = num & 0x1;
  }
  else { // recursion case
    unsigned int left_half_bits = num >> (n_bits_considered / 2);
    const int left_parity = ComputeParityUsingDivideAndConquer(left_half_bits, n_bits_considered / 2);
    const int rght_parity = ComputeParityUsingDivideAndConquer(num, n_bits_considered / 2);
    parity = left_parity ^ rght_parity;
  }  

  return parity;
}


/**
    Print integer in base 2
*/
void PrintIntegerAsBitField(unsigned int  num) {
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