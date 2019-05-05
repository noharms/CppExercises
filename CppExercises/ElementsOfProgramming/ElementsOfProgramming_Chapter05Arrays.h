#pragma once

#include <vector>

typedef struct TWO_BUYS_SELLS {
  int buy_1;
  int buy_2;
  int sell_1;
  int sell_2;
} TwoBuysAndSellsType;

void ElementsOfProgrammingChapter05Arrays();

void ElementsOfProgrammingChapter05Arrays_BubbleSort(std::vector<int>* vec_ptr);
void ElementsOfProgrammingChapter05Arrays_MergeSort(std::vector<int>* vec_ptr);
void ElementsOfProgrammingChapter05Arrays_QuickSort(std::vector<int>* vec_ptr);

void ElementsOfProgrammingChapter05Arrays_IncrementArrayNumber();
void ElementsOfProgrammingChapter05Arrays_AdditionDigitArrays();
void ElementsOfProgrammingChapter05Arrays_MultiplicationDigitArrays();

void ElementsOfProgrammingChapter05Arrays_JumpThroughArray();
void ElementsOfProgrammingChapter05Arrays_BestBuyAndSellOfStock(std::vector<int>* vec_ptr);
void ElementsOfProgrammingChapter05Arrays_RemoveDuplicatesFromSortedVec();


void BubbleSort(std::vector<int>* vec_ptr);
std::vector<int> MergeSort_FirstTry(const std::vector<int>& vec);
void MergeSort(std::vector<int>* vec_ptr, int i_start, int i_end);
void MergeTwoSortedHalves(std::vector<int>* vec_ptr, const int i_start,
  const int i_end, const int n_elems_left);
void QuickSort_FirstTry(std::vector<int>* vec_ptr);
void QuickSort(std::vector<int>* vec_ptr, int ll, int rr);
int FindPivotAndPartition(std::vector<int>* vec_ptr, int ll, int rr);

void IncrementArrayNumber(std::vector<int>* vec_ptr, const int base);
std::vector<int> AddDigitArrays(std::vector<int>* vec_ptr_1,
  std::vector<int>* vec_ptr_2, const int base);
std::vector<int> MultiplyDigitArrays(std::vector<int>* vec_ptr_1,
  std::vector<int>* vec_ptr_2, const int base);
std::vector<int> MultiplyDigitArrayTimesDigit(std::vector<int>* vec_ptr_1,
  const int digit, const int base);

bool IsJumpToEndPossible(const std::vector<int>* vec_ptr);
bool IsJumpToEndPossible_BetterBestCase(const std::vector<int>* vec_ptr);
int MinNumberOfJumpsToReachEnd(const std::vector<int>* vec_ptr);
std::pair<int, int> FindBestBuyAndSellIndices(const std::vector<int>* vec_ptr);
TwoBuysAndSellsType FindBestBuyAndSellIndicesTwoTimes(const std::vector<int>* vec_ptr);
void RemoveDuplicatesFromSortedVector(std::vector<int>* vec_ptr);
void RemoveDuplicatesFromSortedVector_textbook(std::vector<int>* vec_ptr);

void SwapInt(int* a, int* b);
void PrintVector(const std::vector<int>* vec_ptr);
void PrintVectorOfDigitsMSDat0(const std::vector<int>* vec_ptr);