#pragma once

#include <iostream>
#include <stdint.h>


typedef struct Rectangle {
  int x1, x2;
  int y1, y2;

  Rectangle() {
    x1 = 0;
    x2 = 1;
    y1 = 0;
    y2 = 1;
  }

  Rectangle(int xi, int xf, int yi, int yf) {
    bool bad_input = false;
    if (x1 > x2) {
      std::cout << "Bad input. Expected x1 <= x2 for rectangle" << std::endl;
      bad_input = true;
    }
    else if (y1 > y2) {
      std::cout << "Bad input. Expected y1 <= y2 for rectangle" << std::endl;
      bad_input = true;
    }
    if (!bad_input) {
      x1 = xi;
      x2 = xf;
      y1 = yi;
      y2 = yf;
    }
    else {
      Rectangle();
    }
  }
} RectangleType;

void ElementsOfProgrammingChapter04PrimitiveTypes();

void ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLowestSetBit(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_FindLowestSetBit(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_FindLowestUnsetBit(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_RightPropagateLowestSetBit(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_RightPropagateHighestSetBit(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_SwapBits(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_ReverseOrder(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_TestPowerOf2(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeModulus2ton(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_FindClosestSameWeightInteger(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_AdditionByBitwiseOperations();
void ElementsOfProgrammingChapter04PrimitiveTypes_MultiplicationByBitwiseOperations();
void ElementsOfProgrammingChapter04PrimitiveTypes_SubstractionByBitwiseOperations();
void ElementsOfProgrammingChapter04PrimitiveTypes_DivisionByBitwiseOperations();

void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeIntegerPower();

void ElementsOfProgrammingChapter04PrimitiveTypes_ReverseDecimalDigits(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_DecimalPalindrome(uint32_t number);

void ElementsOfProgrammingChapter04PrimitiveTypes_UniformRandomNumberFromCoin();

void ElementsOfProgrammingChapter04PrimitiveTypes_IntersectionOfRectangles();

void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityPerDefinition(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLowestSetBit(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLookupTable(uint32_t number);
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingDivideAndConquer(uint32_t number);


uint32_t UnsetLowestSetBit(uint32_t  num);
uint32_t FindLowestSetBit(uint32_t  num);
uint32_t FindLowestUnsetBit(uint32_t num);
uint32_t RightPropagateLowestSetBit(uint32_t number);
int PositionOfLowestSetBit(uint32_t number);
int PositionOfLowestUnsetBit(uint32_t number);
uint32_t RightPropagateHighestSetBit(uint32_t number);
uint32_t FindHighestSetBit(uint32_t number);
int PositionOfHighestSetBit(uint32_t number);

uint32_t SwapBits(uint32_t number, const int i, const int j);

uint32_t ReverseOrder(uint32_t number);

int CountSetBits(uint32_t number);
bool TestPowerOf2(uint32_t number);

uint32_t ComputeModulus2ton(uint32_t number, const int exponent);

uint32_t FindClosestSameWeightInteger(uint32_t number);
uint32_t FindClosestSameWeightIntegerOrder1Algo(uint32_t number);

uint32_t BitwiseAddition(uint32_t num1, uint32_t num2);
uint32_t BitwiseAdditionSchoolAlgorithm(uint32_t num1, uint32_t num2);
uint32_t BitwiseAdditionSchoolAlgorithmNicer(uint32_t num1, uint32_t num2);
uint32_t BitwiseMultiplication(uint16_t x, uint16_t y);
uint32_t BitwiseSubstraction(uint32_t num1, uint32_t num2);
uint32_t BitwiseDivision(uint32_t num1, uint32_t num2);

double PowerSelfimplemented(double x, uint32_t k);

uint32_t ReverseDecimalDigits(uint32_t number);

bool IsDecimalPalindrome(int number);

int UniformRandomNumberFromCoin(int max_rand);

RectangleType ComputeIntersectionOfRectangles(RectangleType rect1, RectangleType rect2);

bool ComputeParityPerDefinition(uint32_t num);
bool ComputeParityUsingUnsetLowestSetBit(uint32_t  num);
bool ComputeParityUsingLookUpTable(uint32_t  num);
bool ComputeParityUsingDivideAndConquer(uint32_t num, int n_bits_considered);

void PrintIntegerAsBitField(uint32_t  num);
void PrintRectangle(const RectangleType& rect);
