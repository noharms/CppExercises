
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
  PrintVector(&rand_vec);
  rand_vec = rand_vec_backup;


  //--------- Exercise: Merge-Sort
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Merge Sort" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_MergeSort(&rand_vec);
  PrintVector(&rand_vec);
  rand_vec = rand_vec_backup;
  
  //--------- Exercise: Quick-Sort
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Quick-Sort" << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter05Arrays_QuickSort(&rand_vec);
  PrintVector(&rand_vec);
  rand_vec = rand_vec_backup;

  //-------------------------- ARBITRARY ARITHMETIC EXERCISES

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

  //---------------------------------- OTHER ARRAY EXERCISES
  
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
  return;
}

/*
  Exercise description: Use MergeSort algorithm to sort an array.
*/
void ElementsOfProgrammingChapter05Arrays_MergeSort(std::vector<int>* vec_ptr) {
  //*vec_ptr = MergeSort_FirstTry(*vec_ptr);
  MergeSort(vec_ptr, 0, (*vec_ptr).size() - 1);
  return;
}

/*
  Exercise description: Use QuickSort algorithm to sort an array.
*/
void ElementsOfProgrammingChapter05Arrays_QuickSort(std::vector<int>* vec_ptr) {
  //QuickSort_FirstTry(vec_ptr);
  QuickSort(vec_ptr, 0, (*vec_ptr).size() - 1);
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
  const int vec_len = 20;
  const int rand_max = 5;
  for (int i = 0; i < vec_len; ++i) {
    rand_vec.emplace_back(rand() % rand_max);
  }

  // print
  PrintVector(&rand_vec);

  // check
  //bool end_is_reachable = IsJumpToEndPossible(&rand_vec);
  bool end_is_reachable = IsJumpToEndPossible_BetterBestCase(&rand_vec);

  // print
  if (end_is_reachable) {
    std::cout << "Yes, the end of the array is reachable by jumps." << std::endl;
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
*/
void ElementsOfProgrammingChapter05Arrays_BestBuyAndSellOfStock(std::vector<int>* vec_ptr) {

  // print the vector
  PrintVector(vec_ptr);

  // find indices
  std::pair<int, int> buy_sell_pair = FindBestBuyAndSellIndices(vec_ptr);
  int buy_index = buy_sell_pair.first;
  int sell_index = buy_sell_pair.second;

  // print answer
  std::cout << "The best profit is: " << (*vec_ptr).at(sell_index) - (*vec_ptr).at(buy_index);
  std::cout << std::endl;
  std::cout << "Indices: " << buy_index << " " << sell_index << std::endl;

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
  
  // print
  PrintVector(&rand_vec);

  // remove duplicates
  RemoveDuplicatesFromSortedVector(&rand_vec);

  // print
  PrintVector(&rand_vec);

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
std::vector<int> MultiplyDigitArrays(std::vector<int>* vec_ptr_1,
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
  for (int i = 0; i < vec.size(); ++i) {
    if (max_idx_reachable_sofar < i) {
      break;
    }
    int idx_reachable_from_i = i + vec.at(i);
    max_idx_reachable_sofar = std::max(max_idx_reachable_sofar, idx_reachable_from_i);
    if (max_idx_reachable_sofar >= vec.size() - 1) { // already proven
      break;
    }    
  }
  return max_idx_reachable_sofar >= vec.size() - 1 ? true : false;
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
  for (int i = 1; i < vec.size(); ++i) {
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
  std::cout << "Elements of random vector:" << std::endl;
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
      std::cout << "(>10)" << std::endl;
    }
    else {
      std::cout << vec.at(i);
    }
  }
  std::cout << std::endl;
}

