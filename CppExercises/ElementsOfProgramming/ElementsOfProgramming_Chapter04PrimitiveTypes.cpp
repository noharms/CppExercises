

#include "pch.h"

#include "ElementsOfProgramming_Chapter04PrimitiveTypes.h"

#include <iostream>
#include <time.h>
#include <stack>
#include <unordered_map>
#include <random>
#include <vector>
#include <cmath>

void ElementsOfProgrammingChapter04PrimitiveTypes() {
  
  std::cout << "-- Entering ElementsOfProgrammingChapter04PrimitiveTypes " << std::endl;


  // creating larger random numbers than simple rand()
  std::random_device rd;   // non-deterministic generator
  std::mt19937 gen(rd());  // to seed mersenne twister.  
  std::uniform_int_distribution<> dist(1, std::numeric_limits<int>::max());
  uint32_t  number = dist(gen);
  std::cout << "Random number: " << number << std::endl;

  //--------- Exercise: Unset Lowermost-set-bit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Unset Lowermost-set-bit: " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLowestSetBit(number);

  //--------- Exercise: Isolate Lowest-set-bit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: isolate lowes set bit: " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_IsolateLowestSetBit(number);
  
  //--------- Exercise: Right-propagate the lowest-set-bit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Right-propagate the lowest-set-bit " << std::endl;
  std::cout << "------------------------------" << std::endl;
  // make sure the last three bits are 0s
  const uint32_t kMask_LastThreeBits = (0x1u << 2) | (0x1u << 1) | (0x1u);
  ElementsOfProgrammingChapter04PrimitiveTypes_RightPropagateLowestSetBit(number & (~kMask_LastThreeBits));
  
  //--------- Exercise: Swap two bits
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Swap two bits " << std::endl;
  std::cout << "------------------------------" << std::endl;  
  ElementsOfProgrammingChapter04PrimitiveTypes_SwapBits(number);
  
  //--------- Exercise: Reverser order of bits
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Reverse order of bits " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ReverseOrder(number);
  
  //--------- Exercise: Test if power of 2
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: test if power of 2 " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_TestPowerOf2((uint32_t) pow(2, 7));
  ElementsOfProgrammingChapter04PrimitiveTypes_TestPowerOf2((uint32_t) (pow(2, 7) + 1));
  
  //--------- Exercise: Comput modulus 2^n
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: compute modulus 2^n " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_ComputeModulus2ton(number);
  
  //--------- Exercise: Find closest same weight integer
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Find closest same weight int " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_FindClosestSameWeightInteger(number);

  ////--------- exercise: compute parity - using unsetlowestsetbit
  //std::cout << "------------------------------" << std::endl;
  //std::cout << "-- exercise: compute parity: basic " << std::endl;
  //std::cout << "------------------------------" << std::endl;
  //elementsofprogrammingchapter04primitivetypes_computeparityperdefinition(number);

  ////--------- exercise: compute parity - using unsetlowestsetbit
  //std::cout << "------------------------------" << std::endl;
  //std::cout << "-- exercise: compute parity using unsetlowestsetbit " << std::endl;
  //std::cout << "------------------------------" << std::endl;
  //elementsofprogrammingchapter04primitivetypes_computeparityusinglowestsetbit(number);
  //
  ////--------- exercise: compute parity - using lookup table
  //std::cout << "------------------------------" << std::endl;
  //std::cout << "-- exercise: compute parity using lookup table " << std::endl;
  //std::cout << "------------------------------" << std::endl;
  //elementsofprogrammingchapter04primitivetypes_computeparityusinglookuptable(number);
  //
  ////--------- exercise: compute parity - using divide and conquer
  //std::cout << "------------------------------" << std::endl;
  //std::cout << "-- exercise: compute parity using divide and conquer " << std::endl;
  //std::cout << "------------------------------" << std::endl;
  //elementsofprogrammingchapter04primitivetypes_computeparityusingdivideandconquer(number);
  

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

    E.g:   0110 1010 -> 0110 1000

´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLowestSetBit(uint32_t number) {

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
    -> isolate the lowermost-set-bit

    E.g:   0110 1010 -> 0000 0010

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_IsolateLowestSetBit(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // unset the lowermost set bit
  number = IsolateLowestSetBit(number);

  // Print the bits of the modified number
  PrintIntegerAsBitField(number);

  return;
}

/*
    Exercise description:

    Given a bit-field, set all 0s after the lowest-set bit to 1s.

    E.g. 1001 0101 1000  -> 1001 0101 1111
*/
void ElementsOfProgrammingChapter04PrimitiveTypes_RightPropagateLowestSetBit(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  uint32_t modified_number = RightPropagateLowestSetBit(number);

  // print the bits of the number
  PrintIntegerAsBitField(modified_number);

  return;
}

/*
    Exercise description:

    Given a bit-field, swap two bits, e.g.

    1001 0100 swap, (0, 7) -> 0001 0101

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_SwapBits(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  const int swap_i = rand() % 32;
  const int swap_j = rand() % 32;
  uint32_t modified_number = SwapBits(number, swap_i, swap_j);

  // print the bits of the number
  std::cout << "After swap of position " << swap_i;
  std::cout << " and " << swap_j << " the bitfield is:" << std::endl;
  PrintIntegerAsBitField(modified_number);

  return;
}

/*
    Exercise description:

    Given a bit-field, reverse the order of bits, e.g.

    1000 1110 -> 0111 0001

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ReverseOrder(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  uint32_t modified_number = ReverseOrder(number);

  // print the bits of the number
  PrintIntegerAsBitField(modified_number);

  return;
}

/*
    Exercise description:

    Given a bit-field, check if the number is a power of 2 or not.

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_TestPowerOf2(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  if (TestPowerOf2(number)) {
    std::cout << "Yes the given number is a power of 2." << std::endl;
  }
  else {
    std::cout << "No the given number is not a power of 2." << std::endl;
  }

  return;
}

/*
    Exercise description:

    Write a bitwise operation that computes the modulus 2^n for a given n of a given
    number in O(1).

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeModulus2ton(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  const int n = rand() % 32;
  const int modulus_2ton = ComputeModulus2ton(number, n);

  // print result
  std::cout << "The bitwise computed modulus 2^" << n << " is: " << modulus_2ton << std::endl;
  std::cout << "The built-in computed modulus 2^" << n << " is: " << number % ((uint32_t)pow(2, n)) << std::endl;

  return; 
}

/*
    Exercise description:

    The weight of a bitfield is the number of set bits. Find the bitfield that has the
    same weight and is closest, when evaluating the bitfields to numbers.

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_FindClosestSameWeightInteger(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  uint32_t closestsameweightnumber = FindClosestSameWeightInteger(number);

  // print the bits of the number
  PrintIntegerAsBitField(closestsameweightnumber);

  return;
}

//---------------------------- Parity Exercises
/*
    Exercise description:

    Assume you are given a bit-field, say an integer for simplicity.
    -> compute the parity of the bit-field

    E.g:   0110 1010 -> parity 0, because #1 is even
           1110 1010 -> parity 1, because #1 is odd


´*/
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityPerDefinition(uint32_t number) {

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
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLowestSetBit(uint32_t number) {
  
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
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLookupTable(uint32_t number) {
  
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
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingDivideAndConquer(uint32_t number) {
  
  // print the bits of the number
  PrintIntegerAsBitField(number);

  // compute the parity
  bool parity = ComputeParityUsingDivideAndConquer(number, sizeof(uint32_t)*8);

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
    Set the lowest set bit of an integer from 1 to 0
*/
uint32_t UnsetLowestSetBit(uint32_t  num) {
  return num & (num - 1);
}

/**
    Isolate the lowest set bit of an intege
*/
uint32_t IsolateLowestSetBit(uint32_t  num) {
  return num & (~(num - 1));
}

/*
  the idea is that  subtracting 1 from a bit-field will give a bit-field
  which has unset the lowest-set bit and instead 1's in all lesser bits.
  e.g., 1001 0100 - 0000 0001 = 1001 0011
*/
uint32_t RightPropagateLowestSetBit(uint32_t number) {
  if (number) {
    return number | (number - 1);
  }
  else {
    std::cout << "No Bit is set. Nothing is done here." << std::endl;
    return number;
  }
}

/*
  the idea is that we do not need to swap anything if the bits are equal.
  if they are unequal both of them need to flip over, i.e. a simple XOR
  with a mask that has 1's only at the two swap positions will do the job.
*/
uint32_t SwapBits(uint32_t number, const int i, const int j) {
  const bool val_at_i = number & (0x1u << i);
  const bool val_at_j = number & (0x1u << j);
  if (val_at_i != val_at_j) {
    const uint32_t kMask_only_ij = (0x1u << i) | (0x1u << j);
    return number ^ kMask_only_ij;
  }
  else {
    return number;
  }  
}

/*
   the idea is to swap two bits starting from the outermost bits until we reach
   the middle.

   -> a faster algorithm could precompute reverse orders for sub-words and then
      combine the lookups of the sub-words
*/
uint32_t ReverseOrder(uint32_t number) {

  int i = 0, j = 31;

  while (i < j) {
    number = SwapBits(number, i, j); // O(1)
    ++i;
    --j;
  }
  
  return number;
}

/*
  the idea is to count the set bits by repeatedly 
  unsetting the lowest set bit until the number is 0
  and counting how many times this has to be done
  -> O(n) algorithm, where n is the bit-size of the number
*/
int CountSetBits(uint32_t number) {
  int counter = 0;
  while (number) {
    number = UnsetLowestSetBit(number); // O(1)
    ++counter;
  }
  return counter;
}

/*
  the idea is that a bitfield which represents a power of 2 has
  exactly one bit switched on and all others switched of.
*/
bool TestPowerOf2(uint32_t number) {

  // O(1) version that does not count all bits
  if (number == 0x0u) {
    return false;
  }
  else {
    if (UnsetLowestSetBit(number) == 0x0u) {
      return true;
    }
    else {
      return false;
    }
  }

  // O(n) version that counts all bits
  /*if (CountSetBits(number) == 1) {
    return true;
  }
  else {
    return false;
  }*/
}

/*
  the idea is that the modulus is in fact just the bits
  that are right of the n^th bit
*/
uint32_t ComputeModulus2ton(uint32_t number, const int exponent) {
  const uint32_t kMaskRightOfExponentBit = (0x1u << exponent) - 1;
  return number & kMaskRightOfExponentBit;
}

/*
  the idea is that in order to get a number that has the same weight
  we need to flip one bit off and another one on. these two flipped
  bits must be neighbors in order for the resulting numbers to 
  differ as little as possible.

  e.g. in the best case just the two least significant bits:
 
 1000 1001 = 137 -> 1000 1010 = 138 
*/
uint32_t FindClosestSameWeightInteger(uint32_t number) {
  if (number == 0x0u) {
    return 0x1u;
  }
  else if (number == ~0x0u) {
    std::cout << "There is only one 32-bit number with maximum weight." << std::endl;
    return number;
  }
  else {
    const bool val_lsb = number & 0x1u;
    int counter = 0;
    while ((bool)((number >> counter) & 0x1u) == val_lsb) {      
      ++counter;
    }
    // counter is now the index of the first bit that is different from lsb
    const uint32_t kMaskBitAtCounterAndNext= (0x1u << counter) | (0x1u << (counter - 1));
    return number ^ kMaskBitAtCounterAndNext;
  }  
}

//----------- Parity computations
/*
    The definition of the parity is the XOR of all single bits !

    -> read the bit-field bit-by-bit and shifting away the read ones until empty
*/
bool ComputeParityPerDefinition(uint32_t num) {  
  bool parity = 0;
  while (num) {
    if (num & ((uint32_t) 0x1u)) {
      parity ^= (uint32_t) 0x1u ;
    }
    num >>= 1;
  }
  return parity;
}

/**
    this algorithm is O(k), where k is the number of bits set
*/
bool ComputeParityUsingUnsetLowestSetBit(uint32_t  num) {

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
bool ComputeParityUsingLookUpTable(uint32_t num) {

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
  size_t size_of_int_this_machine = sizeof(uint32_t); // expecting 2, 4 or 8
  if (size_of_int_this_machine != 4) {
    std::cout << "Limited the algorithm to 32-bit systems, i.e. 4Bytes for int. Aborting because int=";
    std::cout << size_of_int_this_machine << "." << std::endl;
    return 0;
  }
  else {
    const uint32_t mask_bytes0and1 = 0x0000FFFFu;
    const uint32_t mask_bytes2and3 = 0xFFFF0000u;
    uint32_t bytes0and1 = num & mask_bytes0and1;
    uint32_t bytes2and3 = (num & mask_bytes2and3) >> 16;
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
bool ComputeParityUsingDivideAndConquer(uint32_t num, int n_bits_considered) {

  bool parity = 0;

  if (n_bits_considered == 1) { // base case
    return parity = num & 0x1;
  }
  else { // recursion case
    uint32_t left_half_bits = num >> (n_bits_considered / 2);
    const int left_parity = ComputeParityUsingDivideAndConquer(left_half_bits, n_bits_considered / 2);
    const int rght_parity = ComputeParityUsingDivideAndConquer(num, n_bits_considered / 2);
    parity = left_parity ^ rght_parity;
  }  

  return parity;
}



/**
    Print integer in base 2
*/
void PrintIntegerAsBitField(uint32_t  num) {
  std::cout << "Bitfield represents integer " << num << " : ";
  std::stack<bool> bit_stack;
  //while (num) {  // works for any size, but stops at highest set-bit  
  //  bit_stack.push(num & 1);
  //  num >>= 1;
  //}
  int n_bits_considered = 0;
  while (n_bits_considered < 32) {
    bit_stack.push( (num >> n_bits_considered) & 0x1u);
    ++n_bits_considered;
  }      
  while (!bit_stack.empty()) {
    std::cout << bit_stack.top();
    bit_stack.pop();
  }
  std::cout << std::endl;
  return;
}