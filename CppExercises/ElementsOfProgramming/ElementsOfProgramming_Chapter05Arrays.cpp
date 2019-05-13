
#include "pch.h"

#include "ElementsOfProgramming_Chapter05Arrays.h"

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>


void ElementsOfProgrammingChapter05Arrays() {
    
  std::cout << "-- Entering ElementsOfProgrammingChapter05Arrays " << std::endl;

  // create a random filled array
  srand((unsigned int)time(NULL));
  const int test_length = 10;
  const int max_rand_number = 30;
  std::vector<int> rand_vec;
  for (int i = 0; i < test_length; ++i) {
    rand_vec.emplace_back(rand() % max_rand_number);
  }
  const std::vector<int> rand_vec_backup(rand_vec);
  
  // print vector
  PrintVector(&rand_vec);

  //----------------------------------- SORTING EXERCISES

  //--------- Exercise: Bubble-Sort
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Bubble Sort" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_BubbleSort(&rand_vec);  
  rand_vec = rand_vec_backup;


  //--------- Exercise: Merge-Sort
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Merge Sort" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_MergeSort(&rand_vec);
  rand_vec = rand_vec_backup;
  
  //--------- Exercise: Quick-Sort
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Quick-Sort" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_QuickSort(&rand_vec);  
  rand_vec = rand_vec_backup;

  //----------------------------------- REORDERING EXERCISES

  //--------- Exercise: establish alternating order
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: alternating order" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_EstablishAlternatingOrder(&rand_vec);
  rand_vec = rand_vec_backup;

  //--------- Exercise: Apply a permutation
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Apply a permutation" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_ApplyPermutation(&rand_vec);
  rand_vec = rand_vec_backup;

  //--------- Exercise: Find next in dictionary-ordering
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Find next in dictionary-ordering" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_FindNextPermutation(&rand_vec);
  rand_vec = rand_vec_backup;

  //--------- Exercise: return random subarray at front
  // NOTE: would only be testable by statistically many repetitions
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Random Subarray at front" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_RandomSubarraryAtFront(&rand_vec);
  rand_vec = rand_vec_backup;

  //-------------------------------- ARBITRARY-PREC ARITHMETIC EXERCISES

  //--------- Exercise: Increment digit array
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Increment Digit Array" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_IncrementArrayNumber();
  
  //--------- Exercise: Addition of two digit arrays
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: addition of two digit arrays" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_AdditionDigitArrays();

  //--------- Exercise: Multiplication of two digit arrays
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Multiplication of two digit arrays" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_MultiplicationDigitArrays();

  //-------------------------------------------- OTHER ARRAY EXERCISES
  
  //--------- Exercise: Jumping through array
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: jumping through array" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_JumpThroughArray();
  
  //--------- Exercise: best profit in stock price course
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: best profit" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_BestBuyAndSellOfStock(&rand_vec);
  
  //--------- Exercise: remove duplicates from array
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: remove duplicates" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_RemoveDuplicatesFromSortedVec();
  
  //--------- Exercise: Enumerate Primes
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Enumerate Primes" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_EnumeratePrimes();

  //--------- Exercise: Compute Permutations
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Compute Permutations" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_ComputePermutations();
  
  
  return;

}




/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/


/*
  Exercsie description: Use BubbleSort algorithm to sort an array.
*/
void ElementsOfProgrammingChapter05Arrays_BubbleSort(std::vector<int>* vec_ptr) {
  BubbleSort(vec_ptr);
  PrintVector(vec_ptr);
  return;
}

/*
  Exercise description: Use MergeSort algorithm to sort an array.
*/
void ElementsOfProgrammingChapter05Arrays_MergeSort(std::vector<int>* vec_ptr) {
  //*vec_ptr = MergeSort_FirstTry(*vec_ptr);
  MergeSort(vec_ptr, 0, (*vec_ptr).size() - 1);
  PrintVector(vec_ptr);
  return;
}

/*
  Exercise description: Use QuickSort algorithm to sort an array.
*/
void ElementsOfProgrammingChapter05Arrays_QuickSort(std::vector<int>* vec_ptr) {
  //QuickSort_FirstTry(vec_ptr);
  QuickSort(vec_ptr, 0, (*vec_ptr).size() - 1);
  PrintVector(vec_ptr);
  return;
}


/*
  Exercise description:

  Given an array, reorder the elements such that
    A_i <= A_i+1 , i even
    A_i >= A_i+1 , i odd

  A_0 <= A_1 >= A_2 <= A_3 >= A_4 <= ..
*/
void ElementsOfProgrammingChapter05Arrays_EstablishAlternatingOrder(std::vector<int>* vec_ptr) {
  
  // reorder
  EstablishAlternatingOrder(vec_ptr);

  // print the vector
  PrintVector(vec_ptr);

  return;
}


/*
  Exercise description:

  given an array of length n, and a permutation instruction,
  which comes also in the form of an array of length n where
  the ith entry tells you the index-after-permutation of
  the ith entry in the given array.

  e.g. permutation { 2, 1, 0} applied to {45, 2, 3} gives {3, 2, 45}

*/
void ElementsOfProgrammingChapter05Arrays_ApplyPermutation(std::vector<int>* vec_ptr) {

  // debug: test case
  *vec_ptr = { 17, 11, 14, 8, 1, 18, 29, 3, 25, 3 };

  // print the array
  std::cout << "Permute the following vector" << std::endl;
  PrintVector(vec_ptr);

  // create a random permutation
  const int vec_size = (*vec_ptr).size();
  std::vector<int> permutation;
  for (int i = 0; i < vec_size; ++i) {
    permutation.emplace_back(i);
  }
  for (int i = 0; i < vec_size; ++i) {
    const int swap_i = rand() % vec_size;
    const int swap_j = rand() % vec_size;
    SwapInt(&permutation[0] + swap_i, &permutation[0] + swap_j);
  }

  // debug: test case
  permutation = { 0, 1, 2, 9, 4, 7, 8, 3, 5, 6 };

  // print the permutation
  std::cout << "Applying the following permutation to the vector" << std::endl;
  PrintVector(&permutation);

  // Apply permutation
  //ApplyPermutationExtraSpace(vec_ptr, &permutation);
  ApplyPermutationInplace(vec_ptr, &permutation);

  // print result
  std::cout << "Result after permutation:" << std::endl;
  PrintVector(vec_ptr);

  return;
}

/*
  Exercise description: 

  given an array, the dictionary-ordering defines an order among all permutations
  of the array by comparing entries from left to right, with highest priority being
  at the left, i.e. given

  { 2, 5, 0, 11, 3} the smallest permutation is {0, 2, 3, 5, 11} and the largest
  is {11, 5, 3, 2, 0}.

  note: one can not interprete this as a decimal number because the entries may
  be larger than 10.

  -> find the next larger permutation  

*/
void ElementsOfProgrammingChapter05Arrays_FindNextPermutation(std::vector<int>* vec_ptr) {

  // test example  
  *vec_ptr = { 1, 6, 3, 2, 0 };
  PrintVector(vec_ptr);

  // Reorder
  FindNextPermutation(vec_ptr);

  // print the vector
  PrintVector(vec_ptr);

  return;
}

/*
  Exercise description: 

  given an array of length n and a size k < n, find a random subarray of length k,
  where each possible subarray of that length should be equally likely, and
  move it to the first k entries of the vector.

*/
void ElementsOfProgrammingChapter05Arrays_RandomSubarraryAtFront(std::vector<int>* vec_ptr) {

  // Find random subarray and move to front
  const int k = 4; // rand() % vec_ptr->size();
  RearrangeRandomSubarrayAtFront(vec_ptr, k);

  // print the vector
  PrintVector(vec_ptr);

  return;
}


/*
  Exercise description: given an array of digits that represents
  a number (LSD at beginning), increment the number
*/
void ElementsOfProgrammingChapter05Arrays_IncrementArrayNumber() {
  
  // create array of digits
  std::vector<int> digits;
  const int n_digits = 20;
  const int base = 2;
  for (int i = 0; i < n_digits; ++i) {
    //digits.emplace_back(rand() % base);  
    digits.emplace_back(base - 1);
  }

  // print: msd must appear first
  std::cout << "We want to increment the number:" << std::endl;
  for (int i = digits.size() - 1; i >= 0; --i) {
    std::cout << digits.at(i);
  }
  std::cout << std::endl;

  // Increment
  IncrementArrayNumber(&digits, base);

  // print: result
  std::cout << "Result:" << std::endl;
  for (int i = digits.size() - 1; i >= 0; --i) {
    std::cout << digits.at(i);
  }
  std::cout << std::endl;

  return;
}


/*
  Exercise description: 
  
  given two arrays of digits that represent
  numbers (MSD at beginning), add up the numbers
*/
void ElementsOfProgrammingChapter05Arrays_AdditionDigitArrays() {
  
  // create array of digits
  std::vector<int> digits_1;
  std::vector<int> digits_2;
  const int n_digits_max = 20;
  const int n_digits_1 = 3;
  const int n_digits_2 = 3;
  const int base = 10;
  for (int i = 0; i < n_digits_1; ++i) {    
    digits_1.emplace_back(rand() % base);    
  }
  for (int i = 0; i < n_digits_2; ++i) {
    digits_2.emplace_back(rand() % base);
  }

  // print: msd must appear first
  std::cout << "We want to add the numbers:" << std::endl;
  PrintVectorOfDigitsMSDat0(&digits_1);
  PrintVectorOfDigitsMSDat0(&digits_2);

  // addition
  std::vector<int> sum = AddDigitArrays(&digits_1, &digits_2, base);

  // print: result
  std::cout << "Result:" << std::endl;
  PrintVectorOfDigitsMSDat0(&sum);

  return;
}


/*
  Exercise description:

  given two arrays of digits that represent
  numbers (MSD at beginning), multiply the numbers
*/
void ElementsOfProgrammingChapter05Arrays_MultiplicationDigitArrays() {

  // create array of digits
  std::vector<int> digits_1;
  std::vector<int> digits_2;
  const int n_digits_max = 20;
  const int n_digits_1 = 20;
  const int n_digits_2 = 20;
  const int base = 10;
  for (int i = 0; i < n_digits_1; ++i) {
    digits_1.emplace_back(rand() % base);
  }
  for (int i = 0; i < n_digits_2; ++i) {
    digits_2.emplace_back(rand() % base);
  }

  // print: msd must appear first
  std::cout << "We want to multiply the numbers:" << std::endl;
  PrintVectorOfDigitsMSDat0(&digits_1);
  PrintVectorOfDigitsMSDat0(&digits_2);

  // addition
  std::vector<int> product = MultiplyDigitArrays(&digits_1, &digits_2, base);

  // print: result
  std::cout << "Result:" << std::endl;
  PrintVectorOfDigitsMSDat0(&product);

  return;
}


/*
  Exercise description:

  given array of positive ints, let the numbers represent how far you are
  able to jump forward from that position.

  Test if there is a sequence of jumps that allows you to reach the last element.

*/
void ElementsOfProgrammingChapter05Arrays_JumpThroughArray() {

  // create random vector
  std::vector<int> rand_vec;
  const int vec_len = 7;
  const int rand_max = 5;
  for (int i = 0; i < vec_len; ++i) {
    rand_vec.emplace_back(rand() % rand_max + 1);
  }

  // Hard example: 4 jumps needed !
  // rand_vec = { 2, 3, 2, 2, 1, 1, 4 };

  // print
  PrintVector(&rand_vec);

  // check
  //bool end_is_reachable = IsJumpToEndPossible(&rand_vec);
  bool end_is_reachable = IsJumpToEndPossible_BetterBestCase(&rand_vec);
  int min_jumps_needed = MinNumberOfJumpsToReachEnd(&rand_vec);

  // print
  if (end_is_reachable) {
    std::cout << "Yes, end of array reachable.";
    std::cout << "(minimum " << min_jumps_needed << " jumps needed)" << std::endl;
  }
  else {
    std::cout << "No, the end is not reachable." << std::endl;
  }

  return;
}


/*
  Exercise description:

  given an array of positive integers, let the numbers represent the stock
  price of some share on consecutive days. 

  Find the best profit that could have been made along the course, and return
  the buy day and the sell day.

  Exercise 2:

  Repeat the exercise, but now you are allowed to buy and sell at most twice,
  where the 2nd buy must be after the first sale.
*/
void ElementsOfProgrammingChapter05Arrays_BestBuyAndSellOfStock(std::vector<int>* vec_ptr) {

  // Hard example: 4 jumps needed !
  //*vec_ptr = { 6, 2, 15, 16, 15, 21, 12, 4, 17, 9 };
  //*vec_ptr = { 5, 0, 22, 8, 22, 20, 13, 17, 13, 25 };

  // print the vector
  PrintVector(vec_ptr);

  // find indices
  std::pair<int, int> buy_sell_pair = FindBestBuyAndSellIndices(vec_ptr);
  int buy_index = buy_sell_pair.first;
  int sell_index = buy_sell_pair.second;
  int profit = (*vec_ptr).at(sell_index) - (*vec_ptr).at(buy_index);

  // print answer

  std::cout << "If one buysell is allowed, the max profit is: " << profit;
  std::cout << std::endl;
  std::cout << "Indices: " << buy_index << " " << sell_index << std::endl;
  
  // find indices
  TwoBuysAndSellsType result = FindBestBuyAndSellIndicesTwoTimes(vec_ptr);
  profit = (*vec_ptr).at(result.sell_1) - (*vec_ptr).at(result.buy_1)
    + (*vec_ptr).at(result.sell_2) - (*vec_ptr).at(result.buy_2);
  
  // print answer
  std::cout << "If two buysells are allowed, the max is " << profit << std::endl;
  std::cout << "Indices 1: " << result.buy_1 << " " << result.sell_1 << std::endl;
  std::cout << "Indices 2: " << result.buy_2 << " " << result.sell_2 << std::endl;

  return;
}

/*
  Exercise description:

  Given a sorted array, remove all duplicates. The resulting array
  should be of the same length, but filled up with 0's from the end for
  the removed duplicates.

*/
void ElementsOfProgrammingChapter05Arrays_RemoveDuplicatesFromSortedVec() {

  // create random vector
  std::vector<int> rand_vec;
  const int vec_len = 20;
  const int rand_max = 8;
  for (int i = 0; i < vec_len; ++i) {
    rand_vec.emplace_back(rand() % rand_max);
  }
  
  // sort the vector
  QuickSort(&rand_vec, 0, rand_vec.size() - 1);
  
  // hard test case
  //rand_vec = { 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 7 };

  // print
  PrintVector(&rand_vec);

  // remove duplicates
  //RemoveDuplicatesFromSortedVector(&rand_vec);
  RemoveDuplicatesFromSortedVector_textbook(&rand_vec);

  // print
  PrintVector(&rand_vec);

  return;
}

/*
  Exercise description:

  given a positive integer n, enumerate all prime numbers < n.

*/
void ElementsOfProgrammingChapter05Arrays_EnumeratePrimes() {
  
  // return an array containing the primes
  const int n = 30;
  const std::vector<int> primes = ComputePrimes(n);

  // print  
  PrintVector(&primes);

  return;
}

/*
  Exercise description:

  given an array compute all n! permutations

*/
void ElementsOfProgrammingChapter05Arrays_ComputePermutations() {

  // create random vector
  std::vector<int> rand_vec;
  const int vec_len = 3;
  const int rand_max = 8;
  for (int i = 0; i < vec_len; ++i) {
    rand_vec.emplace_back(rand() % rand_max);
  }
  
  // print
  PrintVector(&rand_vec);
  
  // Compute permutations
  std::vector<std::vector<int>> list_permutations;
  ComputePermutations(&rand_vec, 0, &list_permutations);

  // print permutations
  for (int i = 0; i < list_permutations.size(); ++i) {
    std::vector<int>& perm = list_permutations.at(i);
    std::cout << i << ": ";
    std::for_each(perm.begin(), perm.end(), [](const int&vec_elem) {
      std::cout << vec_elem << ", ";
    });
    std::cout << std::endl;
  }

  return;
}

/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/


/*
  Bubblesort simply traverses the array and sorts in each round 
  the extremal element (usually the largest one) from the unsorted part
  to the end. To get the largest unsorted element, a full traversal
  of the unsorted elements is necessary.

  -> O(n*n)

  */
void BubbleSort(std::vector<int>* vec_ptr) {

  std::vector<int>& vec = *vec_ptr;

  for (size_t i = 0; i < vec.size(); ++i) {    
    size_t idx_max_unsorted = 0;
    int max_unsorted = vec[idx_max_unsorted];
    for (size_t k = 1; k < vec.size() - i; ++k) {
      const int kth_element = vec[k];
      if (kth_element >= max_unsorted) {
        max_unsorted = kth_element;
        idx_max_unsorted = k;
      }
      else { // kth_element < max_unsorted --> Swap, so max_unsorted gets closer to end
        vec[idx_max_unsorted] = kth_element;
        vec[k] = max_unsorted;        
        idx_max_unsorted = k;
      }
    }
    // now the (i+1) largest elements are at the end of the vector
  }

  return;
}


/*
  MergeSort is a divide-and-conquer algorithm: it divides the array
  in two equally long halves until they contain only one element
  and then merges the two halves back into one array in the correct
  order.

  -> recursion depth is log(n)

  -> counting the calls at the same recursion depth together,
     then at each recursion level there are all n elements involved

  -> O(n*log(n))

  Note: the implementation at hand is bad because it uses 
  O(n) + 2*O(n/2) space... the 2*O(n/2) should be enough

*/
std::vector<int> MergeSort_FirstTry(const std::vector<int>& vec) {
  
  const int vec_len = vec.size();
  if (vec_len == 1) {
    return vec;
  }
  else {
    const size_t len_left_subvec = vec_len / 2;
    const size_t len_rght_subvec = vec_len - len_left_subvec;
    std::vector<int> left_subvec(vec.begin(), vec.begin() + len_left_subvec);
    std::vector<int> rght_subvec(vec.begin() + len_left_subvec, vec.end());
    left_subvec = MergeSort_FirstTry(left_subvec);
    rght_subvec = MergeSort_FirstTry(rght_subvec);

    std::vector<int> sorted_vec;
    size_t ll = 0;
    size_t rr = 0;
    while(ll < len_left_subvec && rr < len_rght_subvec) {
      const int next_left = left_subvec[ll];
      const int next_rght = rght_subvec[rr];
      if (next_left < next_rght) {
        sorted_vec.emplace_back(next_left);
        ++ll;
      }
      else {
        sorted_vec.emplace_back(next_rght);
        ++rr;
      }
    }
    // copy possibly remaining elements
    while (ll < len_left_subvec) {
      sorted_vec.emplace_back(left_subvec[ll++]);
    }
    while (rr < len_rght_subvec) {
      sorted_vec.emplace_back(rght_subvec[rr++]);
    }
    return sorted_vec;
  }
}

/*
  Mergesort:

  1. Find middle index
  2. MergeSort(left)
  3. MergeSort(right)
  4. Merge left and right

*/
void MergeSort(std::vector<int>* vec_ptr, const int i_start, const int i_end) {
  const int n_elems = i_end - i_start + 1;
  if (n_elems <= 1) {
    return;
  }
  const int n_elems_left = n_elems / 2;
  MergeSort(vec_ptr, i_start, i_start + n_elems_left - 1);
  MergeSort(vec_ptr, i_start + n_elems_left, i_end);
  MergeTwoSortedHalves(vec_ptr, i_start, i_end, n_elems_left);
  return;
}

/*
  Idea is:

  i think it is not possible to merge the two sorted halves to
  a sorted whole using only O(n) time and 0 space.

  -> let us grant O(n) space to merge in O(n) time
*/
void MergeTwoSortedHalves(std::vector<int>* vec_ptr, const int i_start,
  const int i_end, const int n_elems_left) {
  // n_elems should be at least 2, so that n_elems left/rght both at least 1
  std::vector<int>& vec = *vec_ptr;
  int i = i_start;
  int j = i_start + n_elems_left;
  std::vector<int> vec_backup(vec);
  int k = i_start;
  while(i < i_start + n_elems_left && j <= i_end) {
    const int next_left = vec_backup.at(i);
    const int next_rght = vec_backup.at(j);
    if (next_left <= next_rght) {
      vec.at(k++) = next_left;
      ++i;
    }
    else {
      vec.at(k++) = next_rght;
      ++j;
    }
  }
  while (i < i_start + n_elems_left) {
    vec.at(k++) = vec_backup.at(i++);
  }
  while (j < i_end) {
    vec.at(k++) = vec_backup.at(j++);
  }
  return;
}


/*
  QuickSorts idea is to divide the array to conquer it:

  Step1: pick a pivot
  Step2: put the pivot to correct position
  Step3: put smaller elements left, larger elements right
  Step4: QuickSort the left half and the right half

  The idea is to pick a pivot element, which is put its
  final position in the sorted array. Then the array is 
  divided into two parts where one contains the elements
  smaller than the pivot and the other one the elements
  larger than the pivot. Therefore, it would be optimal
  for the pivot to have half of the other elements be
  smaller than it and the other half be larger than it.
  
  Assuming the pivot is always close to optimal, we will
  need to reach a recursion level of approximately O(log(n))
  to have an array with only two elements, which is
  already sorted once the pivot is put to its correct
  position (i.e. 0 or 1).
  
*/
void QuickSort_FirstTry(std::vector<int>* vec_ptr) {

  std::vector<int>& vec = *vec_ptr;

  if (vec.size() <= 1) {
    return;
  }
  
  // choose first element as pivot
  int pivot_idx = 0;
  const int pivot = vec.at(pivot_idx);

  // put pivot to correct position
  int counter_smaller_elems = 0;
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    if (it - vec.begin() == pivot_idx) {
      continue; // don't count the pivot itself
    }
    if (*it < pivot) {
      ++counter_smaller_elems;
    }
  }
  vec.at(pivot_idx) = vec.at(counter_smaller_elems);
  pivot_idx = counter_smaller_elems;
  vec.at(pivot_idx) = pivot;
  
  // put smaller elemns left, larger/equal right
  int i = 0, j = vec.size() - 1;
  while(true) {
    while (vec.at(i) < pivot) {
      ++i;
    }
    while (vec.at(j) >= pivot && j > pivot_idx) {
      --j;
    }
    if (i >= pivot_idx || j == pivot_idx) {
      break;
    }
    else {
      int temp = vec.at(i);
      vec.at(i) = vec.at(j);
      vec.at(j) = temp;
      ++i;
      --j;
    }
  }

  // make a quicksort on the subarrays
  std::vector<int> left(vec.begin(), vec.begin() + pivot_idx);
  std::vector<int> rght(vec.begin() + pivot_idx + 1, vec.end());
  QuickSort_FirstTry(&left);
  QuickSort_FirstTry(&rght);

  // put the sorted left and rght back
  std::copy(left.begin(), left.end(), vec.begin());
  std::copy(rght.begin(), rght.end(), vec.begin() + pivot_idx + 1);


  return;
}


/*
  QuickSort:

*/
void QuickSort(std::vector<int>* vec_ptr, int i_start, int i_end) {
  // if rr == ll there is only one value, so no sortin necessary
  if (i_end <= i_start) {
    return;
  }
  int pivot_idx = FindPivotAndPartition(vec_ptr, i_start, i_end);
  QuickSort(vec_ptr, i_start, pivot_idx - 1);
  QuickSort(vec_ptr, pivot_idx + 1, i_end);
  return;
}

/*
  We partition around the pivot like  [ < pivot, pivot , >= pivot ].

  The pivot is chosen (at random) to be the first element.

  Algorithm: 
    
  go from left until you find an element that is out of order (i.e. >= pivot)
  go from rght until you find an element that is out of order (i.e. < pivot)
  swap both out of order elements, continue
  repeat until left_ptr and rght_ptr meet (that is the pivot), or switch
  sides (then the last step was a swap; pivot is then the element right of rght_ptr)
  
*/
int FindPivotAndPartition(std::vector<int>* vec_ptr, int i_start, int i_end) {

  if (i_end == i_start) {
    return i_start;
  }
  else if (i_end < i_start) {
    // error case.. should never reach here
  }

  std::vector<int>& vec = *vec_ptr;

  const int pivot = vec.at(i_start);

  int move_direction = 0;  // 1: move i_start to the right, 0: move i_end to the left
  
  while (true) {
    if (move_direction == 0) {
      while (vec.at(i_end) >= pivot && i_end > i_start) {
        --i_end;
      }
    }
    else {
      while (vec.at(i_start) < pivot) {
        ++i_start;
      }
    }    
    if (i_start >= i_end) {
      break;
    }
    else {
      SwapInt(&(vec.at(i_start)), &(vec.at(i_end)));
      move_direction = move_direction ? 0 : 1;
    }    
  }

  return i_start;
}

/*
  Idea: 

  to obtain the ordering 

  A_0 <= A_1 >= A_2 <= A_3 >= A_4 <= ..

  we can always work locally with just looking at two elements !!!

  the start is clear:

  slots 0, 1: if A_0 <= A_1 , continue, if A_0 > A_1 swap.
  slots 1, 2: if A_1 >= A_2 , continue, if A_1 < A_2 swap 

  --> the key insight is that we can swap again without destroying the
      order with the previous element because if A_1 >= A_0 and A_2 > A_1 
      then A_2 > A_1 >= A_0 so that both A_2 and A_1 can be put next to A_0

*/
void EstablishAlternatingOrder(std::vector<int>* vec_ptr) {
  std::vector<int>& vec = *vec_ptr;
  for (size_t i = 0; i < vec.size() - 1; ++i) {
    if (i % 2 == 0) {
      if (vec.at(i) > vec.at(i + 1)) {
        SwapInt(&(vec.at(i)), &(vec.at(i + 1)));
      }
    }
    else {
      if (vec.at(i) < vec.at(i + 1)) {
        SwapInt(&(vec.at(i)), &(vec.at(i + 1)));
      }
    }
  }
  return;
}

/*
  idea:

  start with element 0, the permutation
  tells you to move it to slot j, so do that and continue by checking where
  the element at slot j that was overwritten has to go instead. this way
  jump through the array until all elements are moved to their new position.

  problem: what if you arrive at a slot whose element was already permuted ?
  -> we need to keep track of already permuted slots and in case we reach
  there again, simply find the next unpermuted index

*/
void ApplyPermutationInplace(std::vector<int>* vec_ptr, std::vector<int>* perm_ptr) {
  std::vector<int>& vec = *vec_ptr;
  std::vector<int>& perm = *perm_ptr;    
  for (int i = 0; i < (int)perm.size(); ++i) {
    int i_from = i;
    int val_at_i_from = vec.at(i_from);
    // permute until we reach a slot that was already permuted
    while (perm.at(i_from) >= 0) {      
      int i_target = perm.at(i_from);
      int cache_target = vec.at(i_target); // save the overwritten value
      vec.at(i_target) = val_at_i_from;
      perm.at(i_from) -= perm.size();  // *-1 does not work for 0 !
      // prepare for next round            
      i_from = i_target;
      val_at_i_from = cache_target;
    }
  }
  return;
}

void ApplyPermutationInplace_FirstTry(std::vector<int>* vec_ptr, std::vector<int>* perm_ptr) {
  std::vector<int>& vec = *vec_ptr;
  std::vector<int>& perm = *perm_ptr;
  int permutations_done = 0;
  int i_from = 0;
  int i_to = perm.at(i_from);
  int cache_val_old = vec.at(i_from);
  int min_potentially_unpermuted_idx = 1;
  const int kAlreadyPermuted = -1;
  while (1) {
    // do the permutation
    int cache_val_new = vec.at(i_to);
    vec.at(i_to) = cache_val_old;
    perm.at(i_from) = kAlreadyPermuted;
    ++permutations_done;
    if (permutations_done >= (int)perm.size()) {
      break;
    }
    // next round element at i_to would be moved: check if that permutation was done already !
    if (perm.at(i_to) == kAlreadyPermuted) {
      while (perm.at(min_potentially_unpermuted_idx) == kAlreadyPermuted) {
        ++min_potentially_unpermuted_idx;
      };
      i_from = min_potentially_unpermuted_idx;
      i_to = perm.at(i_from);
      cache_val_old = vec.at(i_from);
    }
    else {
      cache_val_old = cache_val_new;
      i_from = i_to;
      i_to = perm.at(i_to);
    }
  }
  return;
}

/*
  idea:  with additional O(n) space, we can have a very simple O(n) algorithm
*/
void ApplyPermutationExtraSpace(std::vector<int>* vec_ptr, std::vector<int>* perm_ptr) {
  std::vector<int>& vec = *vec_ptr;
  std::vector<int>& perm = *perm_ptr;
  std::vector<int> new_vec(vec.size(), 0);
  for (int i = 0; i < perm.size(); ++i) {
    new_vec.at(perm.at(i)) = vec.at(i);
  }
  vec = new_vec;
  return;
}


/*
  idea: 

  we want to get a larger permutation, so we definitely need to swap a larger number
  from the back with a smaller number from the front. ideally, we want to make the change
  as far to the right as possible because then we are closest to the original array.

  so, go through the array from right to left until you find a possible swap:
  a swap is possible if you find an element that is smaller than the previous one
  (previous means more right here). note this idx and the element and make another round
  from the right to find which is actually the rightmost element larger than this,
  now we know which two elements to swap.

  after the swap sort all elements from the element swapped left to get the smallest
  permutation possible for this subset. note that we do not need a sorting algorithm
  but can simply reverse order because they are already in decreasing order!

  if we do not find any potential swap, it means the input is the largest possible permutation.
    
*/
void FindNextPermutation(std::vector<int>* vec_ptr) {
  std::vector<int>& vec = *vec_ptr;
  int i = - 1;
  for (i = (int)vec.size() - 1; i > 0; --i) {      // step 1: find a decrease from right-to-left
    if (vec.at(i - 1) < vec.at(i)) break;
  }
  if (i > 0) {
    int j = -1;
    for (j = (int)vec.size() - 1; j > 0; --j) {   // step 2: find rightmost larger element
      if (vec.at(j) > vec.at(i - 1)) break;
    }
    SwapInt(&vec.at(i - 1), &vec.at(j));
    std::reverse(vec.begin() + i, vec.end()); // O(n)
  }
  else {
    vec = {};
  }
  return;
}

/*
   O(n*n)
 */
void FindNextPermutation_FirstTry(std::vector<int>* vec_ptr) {
  std::vector<int>& vec = *vec_ptr;
  for (int i = (int)vec.size() - 1; i > 0; --i) {
    int smaller_idx = -1;
    for (int j = i - 1; j > 0; --j) {
      if (vec.at(j) < vec.at(i)) {
        smaller_idx = j;
        break;
      }
    }
    if (smaller_idx >= 0) {
      SwapInt(&vec.at(i), &vec.at(smaller_idx));
      QuickSort(vec_ptr, smaller_idx + 1, vec.size() - 1);
      break;
    }
  }
  return;
}


/*
  Idea:  simply make k calls to the random number generator, that
  should return of the unpicked elements at equal probability.
*/
void RearrangeRandomSubarrayAtFront(std::vector<int>* vec_ptr, const int k) {
  std::vector<int>& vec = *vec_ptr;
  for (int i = 0; i < k; ++i) {
    const int i_pick_random = rand() % (vec.size() - i) + i;
    SwapInt(&vec.at(i), &vec.at(i_pick_random));
  }
  return;
}


/*
  Incrementing a number is easy. The only caveat is to mind the
  carryover 1.
*/
void IncrementArrayNumber(std::vector<int>* vec_ptr, const int base) {
  std::vector<int>& vec = *vec_ptr;
  size_t i = 0;
  int carryover = 0;
  do {
    int digit_sum = vec.at(i) + 1;
    carryover = digit_sum / base;
    vec.at(i++) = digit_sum % base;    
  } while (carryover && i < vec.size());
  // if we reached msd and still have carryover, we need one more digit
  if (carryover) {
    vec.emplace_back(1);
  }
  return;
}

/*
  Addition of digit arrays:

  just go through all digits and add up the digits, carrying
  over excess-digits.

*/
std::vector<int> AddDigitArrays(std::vector<int>* vec_ptr_1,
  std::vector<int>* vec_ptr_2, const int base) {

  std::vector<int>& vec_big = (*vec_ptr_1).size() > (*vec_ptr_2).size() ? *vec_ptr_1 : *vec_ptr_2;
  std::vector<int>& vec_small = (*vec_ptr_1).size() > (*vec_ptr_2).size() ? *vec_ptr_2 : *vec_ptr_1;
  std::vector<int> sum;

  int next_small = vec_small.size() - 1;
  int next_big = vec_big.size() - 1;
  int carryover = 0;  

  while (next_big >= 0) {
    int digit_sum = vec_big.at(next_big--) + carryover;
    if (next_small >= 0) {
      digit_sum += vec_small.at(next_small--);
    }      
    int digit = digit_sum % base;    
    sum.insert(sum.begin(), digit);
    carryover = digit_sum / base;
  }  
  if (carryover) {    
    sum.insert(sum.begin(), carryover);
  }
  return sum;
}


/*
  Multiplication of digit arrays:

  we can break down the multiplication into multiplications with a digit,
  shifts, and additions
  

  abcde * fgh = abcde * (f*10^2 + g*10^1 + h*10^1)
              =  (abcde * f) * 10^2
               + (abcde * g) * 10^1
               + (abcde * h) * 10^0

*/
std::vector<int> MultiplyDigitArrays_RestrictResultVectorDigitsToBeSmallerThanBase(std::vector<int>* vec_ptr_1,
  std::vector<int>* vec_ptr_2, const int base) {
  
  std::vector<int>& vec_big = (*vec_ptr_1).size() > (*vec_ptr_2).size() ? *vec_ptr_1 : *vec_ptr_2;
  std::vector<int>& vec_small = (*vec_ptr_1).size() > (*vec_ptr_2).size() ? *vec_ptr_2 : *vec_ptr_1;
  std::vector<int> product;

  for (int i = vec_small.size() - 1; i >= 0; --i) {
    const int ith_digit_in_small = vec_small.at(i);
    std::vector<int> big_x_digit = MultiplyDigitArrayTimesDigit(&vec_big, ith_digit_in_small, base);
    // since the msd is the first, we can easily shift the number left by appending 0's
    const unsigned int power_of_digit = (vec_small.size() - 1 - i);
    big_x_digit.insert(big_x_digit.end(), power_of_digit, 0);    
    product = AddDigitArrays(&product, &big_x_digit, base);
  }

  return product;
}


std::vector<int> MultiplyDigitArrayTimesDigit(std::vector<int>* vec_ptr_1,
  const int digit, const int base) {
  if (digit >= base) {
    // error case.. 
    std::cout << "ERROR.. should not reach here" << std::endl;
  }

  std::vector<int>& vec = *vec_ptr_1;
  std::vector<int> product;
  int carryover = 0;

  for (int i = vec.size() - 1; i >= 0; --i) {
    const int temp_product = vec.at(i) * digit + carryover;
    const int new_digit = temp_product % base;
    product.insert(product.begin(), new_digit);
    carryover = temp_product / base;
  }
  if (carryover) {
    product.insert(product.begin(), carryover);
  }

  return product;
}

/*
  idea: 
  
  multiply digit by digit and continuously add to the result vector
  
  Note convention:

  { MSD at index 0, ..., LSD at index size() -1 } 

*/
std::vector<int> MultiplyDigitArrays(std::vector<int>* vec_ptr_1,
  std::vector<int>* vec_ptr_2, const int base) {
  const std::vector<int>& vec_1 = *vec_ptr_1;
  const std::vector<int>& vec_2 = *vec_ptr_2;  
  const int max_digits_product = vec_1.size() + vec_2.size();
  std::vector<int> product(max_digits_product, 0);
  // start with the LSD's, so they go to last slot in product
  for (int i = (int)vec_1.size() - 1; i >= 0; --i) {    
    for (int j = (int)vec_2.size() - 1; j >= 0; --j) {            
      product.at(i + j + 1) += vec_1.at(i) * vec_2.at(j);
    }
  }
  // carry-over the values that have become larger than base
  for (int k = max_digits_product - 1; k > 0; --k) {
    product.at(k - 1) += product.at(k) / base;
    product.at(k) %= base;
  }
  if (product.at(0) > base) {
    // should not reach here, if logic is correct
    std::cout << "Error: should not reach here." << std::endl;
  }
  return product;
}

/*
  let elements contain the maximum steps you can jump forward from there:

  {1, 2, 0, 0, 3, 1}  --> you could never reach beyond 4th element.

  Idea is that only 0's can stop us. So go from end and check if you
  always find an earlier element that allows to jump here. if you
  reach to the first element this way, there is a way.

  -> O(n), in best, worst and average case; always go to first element

*/
bool IsJumpToEndPossible(const std::vector<int>* vec_ptr) {
  const std::vector<int>& vec = *vec_ptr;
  int idx_under_check = vec.size() - 1;
  int distance_to_idx_under_check = 0;
  for (int i = idx_under_check - 1; i >= 0; --i) {
    ++distance_to_idx_under_check;
    if (vec.at(i) >= distance_to_idx_under_check) {
      idx_under_check = i;
      distance_to_idx_under_check = 0;
    }
  }
  return (distance_to_idx_under_check == 0 ? true : false);
}

/*
  -> O(n) in average and worst case, but O(1) in best case
*/
bool IsJumpToEndPossible_BetterBestCase(const std::vector<int>* vec_ptr) {
  const std::vector<int>& vec = *vec_ptr;
  int max_idx_reachable_sofar = 0;
  for (size_t i = 0; i < vec.size(); ++i) {
    if (max_idx_reachable_sofar < (int)i) {
      break;
    }
    int idx_reachable_from_i = i + vec.at(i);
    max_idx_reachable_sofar = std::max(max_idx_reachable_sofar, idx_reachable_from_i);
    if (max_idx_reachable_sofar >= (int)(vec.size() - 1)) { // already proven
      break;
    }    
  }
  return max_idx_reachable_sofar >= (int)(vec.size() - 1) ? true : false;
}

/*
  idea is to keep track of the maximum index reachable so far. if this 
  index is smaller than the end, we at least need one more jump.
  in fact, we have to traverse all elements until the current maximum index
  reachable so far and check which of the elements allows the farthest next jump.
  if that jump does not reach the end, we certainly need one more jump and
  then need to check how many additional more.
*/
int MinNumberOfJumpsToReachEnd(const std::vector<int>* vec_ptr) {
  const std::vector<int>& vec = *vec_ptr;

  int max_idx_reachable_withcurrjump = vec.at(0);
  int max_idx_reachable_withnextjump = -1;
  int n_jumps_needed = 1;

  for (int i = 0; i < (int)vec.size(); ++i) {
    if (max_idx_reachable_withnextjump >= (int)(vec.size() - 1)) {
      ++n_jumps_needed;
      // this jump is enough to reach the end      
      break;
    }
    if (i <= max_idx_reachable_withcurrjump) {
      max_idx_reachable_withnextjump = std::max(max_idx_reachable_withnextjump, i + vec.at(i));
    }
    else {
      if (i <= max_idx_reachable_withnextjump) {
        // to reach this index one more jump was needed
        ++n_jumps_needed;
        max_idx_reachable_withcurrjump = max_idx_reachable_withnextjump;
        max_idx_reachable_withnextjump = i + vec.at(i);
      }
      else {
        // there is no jump that leads us here, cannot reach end
        n_jumps_needed = -1;
        break;
      }      
    }
  }

  return n_jumps_needed;
}

/*
  we can simply traverse the array and track the minimum and the profit
  if we were to sell now and then compare against the best profit seen so far.

  -> O(n)
*/
std::pair<int, int> FindBestBuyAndSellIndices(const std::vector<int>* vec_ptr) {

  const std::vector<int>& vec = *vec_ptr;
   
  int min_price_sofar = vec.at(0);
  int index_min_sofar = 0;
  int best_sell = 0;
  int index_best_sell = 0;
  int index_best_buy = 0;

  for (int i = 1; i < (int)vec.size(); ++i) {
    int current_price = vec.at(i);
    if (current_price < min_price_sofar) { // new minimum found
      min_price_sofar = current_price;
      index_min_sofar = i;
    }
    else {
      int current_sell = current_price - min_price_sofar;
      if (current_sell > best_sell) { // new highest jump found
        best_sell = current_sell;
        index_best_buy = index_min_sofar;
        index_best_sell = i;
      }
    }
  }

  return { index_best_buy, index_best_sell };
}

/*
  idea: 

  the main difficulty is that after a complete round through the array
  we may have found the best single buy-sell pair, but when two buys-sells are
  allowed we have still no clue where they would be ! e.g. could 
  be possible that the two buy-sells are somewhere in the range spanned
  by the single best buy-sell

                  x
    x        x   xx
   xxx     xxxx xxxxx
  abcdefghijklmnopqrstu
       xxxx    x    x
        xx
        x

  --> single best buy-sell from g-q
  --> double best buy-sell from g-l , n-q

  The problem can be solved as an optimisation problem:
  calculate for each day how much the first sell would maximally give
  if the array would end that day and then check how much the second
  sell would maximally give if the second buy would have to
  be in the remaining array. this way you know where to split
  the array so that a buy in the first part combined with a buy 
  in the second part brings the maximum profit.

  -> needs O(n) additional space
*/
TwoBuysAndSellsType FindBestBuyAndSellIndicesTwoTimes(const std::vector<int>* vec_ptr) {
  const std::vector<int>& vec = *vec_ptr;
  
  // compute maximum profit for each day thinking it was the last for sell
  int maxprofit_possible_sofar = 0;
  int min_price_sofar = vec.at(0);
  std::vector<int> maxprofits_possible_sell1untiltoday(vec.size(), -1);
  for (size_t i = 1; i < vec.size(); ++i) {
    int price_at_i = vec.at(i);
    // at each step, two things can happen:
    // i) new min_price
    // ii) old min_price but possibly higher profit because current value is new max
    if (price_at_i < min_price_sofar) {
      min_price_sofar = price_at_i;      
    }
    else {
      int maxprofit_selltoday = price_at_i - min_price_sofar;
      maxprofit_possible_sofar = std::max(maxprofit_possible_sofar, maxprofit_selltoday);
    }
    maxprofits_possible_sell1untiltoday.at(i) = maxprofit_possible_sofar;
  }

  // compute maximum profit for each day thinking it was the first for buy
  int max_price_sofar = vec.at(vec.size() - 1);
  std::vector<int> maxprofits_possible_buy2allowed_fromhere(vec.size(), -1);
  maxprofit_possible_sofar = 0;
  for (size_t i = vec.size() - 2; i > 0; --i) {
    int price_at_i = vec.at(i);
    // at each step, two things can happen:
    // i) new max_price
    // ii) old max_price but possibly higher profit because current value is new min
    if (price_at_i > max_price_sofar) {
      max_price_sofar = price_at_i;
    }
    else {
      int maxprofit_buytoday = max_price_sofar - price_at_i;
      maxprofit_possible_sofar = std::max(maxprofit_possible_sofar, maxprofit_buytoday);
    }
    maxprofits_possible_buy2allowed_fromhere.at(i) = maxprofit_possible_sofar;
  }
  
  // compute the total maximum possible for each day
  std::vector<int> maxprofits_possible_total(vec.size(), -1);
  for (size_t i = 1; i < vec.size() - 1; ++i) {
    int maxprofit_selluntiltoday_buyfromtomorrow =
      maxprofits_possible_sell1untiltoday.at(i)
      + maxprofits_possible_buy2allowed_fromhere.at(i + 1);
    maxprofits_possible_total.at(i) = maxprofit_selluntiltoday_buyfromtomorrow;
  }

  // find the optimum split day
  int split_day = std::max_element(maxprofits_possible_total.begin(), maxprofits_possible_total.end()) - maxprofits_possible_total.begin();

  // find indices for buys/sells
  std::vector<int> part_1(vec.begin(), vec.begin() + split_day + 1);
  std::vector<int> part_2(vec.begin() + split_day + 1, vec.end());
  std::pair<int, int> buysell_1 = FindBestBuyAndSellIndices(&part_1);
  std::pair<int, int> buysell_2 = FindBestBuyAndSellIndices(&part_2);

  TwoBuysAndSellsType result;
  result.buy_1 = buysell_1.first;
  result.buy_2 = buysell_2.first + part_1.size();
  result.sell_1 = buysell_1.second;
  result.sell_2 = buysell_2.second + part_1.size();
  return result;
}

/*
  If one would allow O(n) extra space, this would be easy.
  
  Without extra space, one needs the following key insight:
  as soon as there is a single duplicate, all following
  elements need to be shifted. an efficient way will be
  to not shift at the moment you find a duplicate, but
  rather keep track of where the duplicates are and once
  you reach a non-duplicate move it to the first of
  the overwritable elements.

*/
void RemoveDuplicatesFromSortedVector(std::vector<int>* vec_ptr) {
  std::vector<int>& vec = *vec_ptr;
  
  int prev_val = vec.at(0);
  bool duplicate_found = false;
  int idx_duplicate = 0;
  for (size_t i = 1; i < vec.size(); ++i) {
    int val = vec.at(i);
    if (val == prev_val) {
      if (duplicate_found == false) {
        duplicate_found = true;
        idx_duplicate = i;
        vec.at(i) = 0;
        // note: prev_val not updated
      }
      else {
        vec.at(i) = 0;
      }
    }
    else {
      prev_val = val;
      if (duplicate_found) {        
        SwapInt(&(vec.at(i)), &(vec.at(idx_duplicate)));
        ++idx_duplicate;
      }
    }
  }

  return;
}

void RemoveDuplicatesFromSortedVector_textbook(std::vector<int>* vec_ptr) {
  std::vector<int>& vec = *vec_ptr;
  int write_index = 1;
  for (size_t i = 1; i < vec.size(); ++i) {
    if (vec.at(i) != vec.at(write_index - 1)) {
      vec.at(write_index++) = vec.at(i);
    }
    if (i > write_index - 1) {
      vec.at(i) = -1;
    }
    
  }
  return;
}

/*
  idea: 

  the brute-force approach would be to go through all numbers < n and test if
  it is a prime. the test if it is a prime is O(n^1/2), so over all  O(n^3/2)

  we cannot improve very much, but allowing us O(n) extra space, we
  can remove with each new number p all multiples of it from the candidates,
  i.e. remove n/p candidates. we do not need to test if a number is prime,
  we automatically know it, if we reach there and it is not already outruled to
  be a candidate.

  So first we need to outrule O(n/2), then O(n/3), then O(n/5), ... . Turns out
  this is 

  --> O(n) * log log (n)

*/
std::vector<int> ComputePrimes(const int n) {
  // take care: huge memory costs! n <= int_max =2G,
  //            with at least 8G RAM no problem
  std::vector<bool> candidates(n, 1);
  candidates.at(0) = 0;
  candidates.at(1) = 0;  
  // go through
  std::vector<int> primes_found;
  for (long i = 2; i < n; ++i) {
    if (candidates.at(i)) {
      primes_found.emplace_back(i);
      // remove multiples from the candidate list
      // note: it is enough to start at index p^2 
      // because for each k < p, all mutliples have
      // already been erased, i.e. also p*k;
      // thus we can start with p*p to erase further
      // candidates and save some time
      for (long multiple = i * i; multiple < n; multiple += i) {
        candidates.at(multiple) = 0;
      }
    }
  }
  return primes_found;
}

/*
  Idea:

  compute permutations recursively by actually doing each permutation.
  
  start with the vector as it is. then start to do permutations from the
  back, always reverting the permutation after all permutaitons of the
  following elements have been considered. 
  
  note: re_use the given vector to permute in place

  complexity:   n + n * ( (n-1) + (n-1) * ( (n-2) + (n-2) * (...) ) )
          = n * (1 +    ( (n-1) + (n-1) * ( (n-2) + (n-2) * (...) ) )
          ~ O(n * n!)

*/
void ComputePermutations(std::vector<int>* vec_ptr, const int i0, 
  std::vector<std::vector<int>>* permutations_ptr) {

  std::vector<int>& vec = *vec_ptr;

  if (i0 == (int)vec.size() - 1) {  // reached last element
    permutations_ptr->emplace_back(vec);
    return;
  }
  for (int i = i0; i < (int)vec.size(); ++i) {
    SwapInt(&vec.at(i0), &vec.at(i));
    ComputePermutations(vec_ptr, i0 + 1, permutations_ptr);
    SwapInt(&vec.at(i), &vec.at(i0));
  }  

  return;
}

/*
  Standard Swap 
*/
void SwapInt(int* a, int* b) {
  const int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void PrintVector(const std::vector<int>* vec_ptr) {
  //const std::vector<int> vec = *vec_ptr;
  std::cout << "Elements of vector:" << std::endl;
  std::for_each(vec_ptr->begin(), vec_ptr->end(), [](const int& vec_elem) {
    std::cout << "  " << vec_elem << std::endl;
  });
  std::cout << std::endl;
  return;
}

void PrintVectorOfDigitsMSDat0(const std::vector<int>* vec_ptr) {
  const std::vector<int>& vec = *vec_ptr;
  for (size_t i = 0; i < vec.size(); ++i) {
    if (vec.at(i) >= 10) {
      std::cout << "(>10)";
    }
    else {
      std::cout << vec.at(i);
    }
  }
  std::cout << std::endl;
}

