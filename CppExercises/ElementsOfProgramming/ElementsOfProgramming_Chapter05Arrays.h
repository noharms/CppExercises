#pragma once

#include <vector>

void ElementsOfProgrammingChapter05Arrays();

void ElementsOfProgrammingChapter05Arrays_BubbleSort(std::vector<int>* vec_ptr);
void ElementsOfProgrammingChapter05Arrays_MergeSort(std::vector<int>* vec_ptr);
void ElementsOfProgrammingChapter05Arrays_QuickSort(std::vector<int>* vec_ptr);


void BubbleSort(std::vector<int>* vec_ptr);

std::vector<int> MergeSort_FirstTry(const std::vector<int>& vec);
void MergeSort(std::vector<int>* vec_ptr, int i_start, int i_end);
void MergeTwoSortedHalves(std::vector<int>* vec_ptr, const int i_start,
  const int i_end, const int n_elems_left);

void QuickSort_FirstTry(std::vector<int>* vec_ptr);
void QuickSort(std::vector<int>* vec_ptr, int ll, int rr);
int FindPivotAndPartition(std::vector<int>* vec_ptr, int ll, int rr);
void SwapInt(int* a, int* b);

void PrintVector(const std::vector<int>* vec_ptr);