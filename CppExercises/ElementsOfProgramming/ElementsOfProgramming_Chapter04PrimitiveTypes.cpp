

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
  std::cout << "-- Exercise: Find lowest set bit: " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_FindLowestSetBit(number);
  
  //--------- Exercise: Mark Lowest-Unset-bit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Find lowest unset bit: " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_FindLowestUnsetBit(number);
  
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
  
  //--------- Exercise: Multiplication by bitwise operations
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Multiplication by bitwise operatiosn " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter04PrimitiveTypes_MultiplicationByBitwiseOperations();

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

    Assume you are given a bit-field
    -> isolate the lowermost-set-bit

    E.g:   0110 1010 -> 0000 0010

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_FindLowestSetBit(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // unset the lowermost set bit
  number = FindLowestSetBit(number);

  // Print the bits of the modified number
  PrintIntegerAsBitField(number);

  return;
}

/*
    Exercise description:

    Assume you are given a bit-field
    -> mark the lowest unset bit in new bitmask

    e.g.  1001 0111 -> 0000 1000

*/
void ElementsOfProgrammingChapter04PrimitiveTypes_FindLowestUnsetBit(uint32_t number) {

  // print the bits of the number
  PrintIntegerAsBitField(number);

  // unset the lowermost set bit
  const uint32_t kBitMaskLowestUnsetBit = FindLowestUnsetBit(number);

  // Print the bits of the modified number
  PrintIntegerAsBitField(kBitMaskLowestUnsetBit);

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
  //uint32_t closestsameweightnumber = FindClosestSameWeightInteger(number);
  uint32_t closestsameweightnumber = FindClosestSameWeightIntegerOrder1Algo(number);

  // print the bits of the number
  PrintIntegerAsBitField(closestsameweightnumber);

  return;
}

/*
  Exercise description:

  Implement your own version of a multiplication of two nonnegative integers using only bitwise operations,
  &, |, ~, ^, >>, << 
  and assignment operators. In particular, you are not allowed to use arithmetic operators, +, -, * 
 */
void ElementsOfProgrammingChapter04PrimitiveTypes_MultiplicationByBitwiseOperations() {

  // get two small random numbers (they must be < 2^16, since the result can maximally be 2^32-1)
  uint16_t number1 = rand() % std::numeric_limits<uint16_t>::max();
  uint16_t number2 = rand() % std::numeric_limits<uint16_t>::max();
  std::cout << "Multiplying " << number1 << " * " << number2 << std::endl;
  
  // compute the product
  uint32_t product = BitwiseMultiplication(number1, number2);

  // output the result
  std::cout << "Bitwise implementation yields: " << product << std::endl;
  std::cout << "Built-in multiplication yields: " << number1 * number2 << std::endl;

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
    Isolate the lowest set bit of an integer

    idea:  x    = 1001 1000
           x-1  = 1001 0111
         ~(x-1) = 0110 1000
     x & ~(x-1) = 0000 1000
       
*/
uint32_t FindLowestSetBit(uint32_t  num) {
  return num & (~(num - 1));
}

/*
  Isolate the lowest unset bit of a bitfield

  idea:    x               = 1010 0111
           x+1             = 1010 1000
        x^(x+1)            = 0000 1111
       (x^(x+1)) + 1       = 0001 0000
      ((x^(x+1)) + 1) >> 1 = 0000 1000
*/
uint32_t FindLowestUnsetBit(uint32_t num) {
  return ((num ^ (num + 0x1u)) + 0x1u) >> 1;
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
  the idea is to right-shift until a 1 appears at the lsb,  -> O(n) algo
*/
int PositionOfLowestSetBit(uint32_t number) {
  if (number == 0x0u) {
    return -1; // no bit is set
  }
  else {
    int pos = 0;
    while ((number & 0x1u) == 0x0u) {
      number >>= 1;
      ++pos;
    }
    return pos;
  }  
}

/*
  the idea is to right-shift until a 0 appears at the lsb,  -> O(n) algo
*/
int PositionOfLowestUnsetBit(uint32_t number) {
  if (number == ~0x0u) {
    return -1; // all bits are set
  }
  else {
    int pos = 0;
    while ((number & 0x1u) == 0x1u) {
      number >>= 1;
      ++pos;
    }
    return pos;
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

/*
  the idea is that we need to find the two least significant bits that
  are different from another and then flip them.

  in the above algorithm we tried to find these two by traversing the bits,
  one by one, which is obviously linear.

  in order to improve that we need to find operations that yield the two bits
  automatically, without traversal. this can be done with the help of a
  case distinction:

    if the LSB is 0, then we need to find the first 1, which is easily doable
    (FindLowestSetBit is O(1)). 
    if the LSB is 1, then we need to find the first 0, which is as well easily
    doable (FindLowestUnsetBit is O(1))
*/
uint32_t FindClosestSameWeightIntegerOrder1Algo(uint32_t number) {

  const bool val_lsb = (number & 0x1u);

  if (val_lsb == 0) {
    const uint32_t kMaskLowestSetBit = FindLowestSetBit(number);
    return number ^ (kMaskLowestSetBit | (kMaskLowestSetBit >> 1));
  }
  else {
    const uint32_t kMaskLowestUnsetBit = FindLowestUnsetBit(number);
    return number ^ (kMaskLowestUnsetBit | (kMaskLowestUnsetBit >> 1));
  }
}

/*
  the idea for bitwise implementation of multiplication (no +,*,-,/ allowed) is:

  when multiplying multiple-digit numbers one basically
  takes the one number multiplies it with each digit of the other number and adds up
  the results. this holds for multiplication in binary as well as in decimal base.

  key insights:
    - we can imitate multiplications by 2^n by leftshift of the bitfield by n.
    - we can imitate addition of two bitfields by OR of the bitfields
      plus a certain procedure to account for bits present in both fields
  
  So one basically needs a loop over all bits in bitfield2:

    temporary_result = 0
    foreach bit in bitfield2:
      addition = leftshift bitfield1 by the corresponding shift
      add addition to temporary result
      
  e.g.  5 * 10 = 50
                                           0101 * 1010 
    --> bit at 2^1 in bitfield2:           1010
    --> bit at 2^3 in bitfield2:   +  0010 1000 
    --------------------------------------------------
                                      0011 0010 = 50

  The problem is the implementation of the + of the two bitfields using only
  bitwise operations:
  While a simple OR of the two bitfields will almost bring the 
  result, it fails if both bitfields have a 1 at the same position.
  In that case one needs to flip the bit to 0 and instead switch
  on the following bit. However, if the next bit is already a 1,
  again this 1 has to become a 0 and the next one has to be flipped on.
  
*/
uint32_t BitwiseMultiplication(uint16_t x, uint16_t y) {

  // TODO: handle 0's

  uint32_t result = 0x0u;
  uint32_t x_32 = (uint32_t)x;
  uint32_t y_32 = (uint32_t)y;

  while (y_32) {
    int pos_lowest_set_bit_y = PositionOfLowestSetBit(y_32);  // O(n)    
    uint32_t summand = x_32 << pos_lowest_set_bit_y;

    // save those bits that are present in both: they need special treatment
    // when adding them up
    uint32_t bits_problematic = result & summand;
        
    // 1. ADDITION OF UNPROBLEMATIC BITS 
    result = result | summand;

    // 2. ADDITION OF THE PROBLEMATIC BITS 
    // if a power of 2 appears in both the result and the new summand,
    // one of them is not taken care of when doing the OR in step 1.
    while (bits_problematic) {
      int pos_lowest_problematic = PositionOfLowestSetBit(bits_problematic);  // O(n)
      int offset_next_free_slot = PositionOfLowestUnsetBit(result >> pos_lowest_problematic);
      // unset the 1's, set the 1 at the next free slot
      uint32_t mask_problematic_bit = (0x1u << pos_lowest_problematic);
      uint32_t mask_free_bit = (0x1u << pos_lowest_problematic) << offset_next_free_slot;
      while (mask_problematic_bit != mask_free_bit) {  // move the "pointer" to the problematic bit until free slot
        result = result & (~mask_problematic_bit); // set 0 at the problematic bit
        mask_problematic_bit <<= 1;
      }
      result = result | mask_free_bit;
      // the lowest one of the problematic bits has now been taken care of in the result,
      // so cut it from the problematic ones
      bits_problematic &= ~(0x1u << pos_lowest_problematic); 
               
      // since several 1's in the result may have been set 0 (at least one),
      // we need to re-check which bits remain problematic at all !
      // possibly some of the problematic bits are now already free and can simply be set!
      // e.g.   
      //           result    = 0111 0101 
      //           summand   = 0111 0010
      //  result | summand   = 0111 0111
      // -> problematic bits = 0111 0000
      // after adding the first of the problematic bits: 
      //           result    = 1000 0111
      // -> so now the other problematic bits could simply be added already !
      //
      // 1. check again which bits are still problematic
      uint32_t bits_problematic_still = result & bits_problematic;
      // 2. get the now unproblematic bits from the summand into the result by OR
      result = result | bits_problematic;

      // continue with the sill problematic bits
      bits_problematic = bits_problematic_still;
    }

    // this bit of y has been processed in the multiplication: unset it
    y_32 = UnsetLowestSetBit(y_32);
  }

  return result;
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