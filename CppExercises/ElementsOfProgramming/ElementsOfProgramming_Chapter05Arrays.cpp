
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
  *vec_ptr = MergeSort(*vec_ptr);
  return;
}

/*
  Exercise description: Use QuickSort algorithm to sort an array.
*/
void ElementsOfProgrammingChapter05Arrays_QuickSort(std::vector<int>* vec_ptr) {
  QuickSort(vec_ptr);
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
std::vector<int> MergeSort(const std::vector<int>& vec) {
  
  const int vec_len = vec.size();
  if (vec_len == 1) {
    return vec;
  }
  else {
    const size_t len_left_subvec = vec_len / 2;
    const size_t len_rght_subvec = vec_len - len_left_subvec;
    std::vector<int> left_subvec(vec.begin(), vec.begin() + len_left_subvec);
    std::vector<int> rght_subvec(vec.begin() + len_left_subvec, vec.end());
    left_subvec = MergeSort(left_subvec);
    rght_subvec = MergeSort(rght_subvec);

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
void QuickSort(std::vector<int>* vec_ptr) {

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
  QuickSort(&left);
  QuickSort(&rght);

  // put the sorted left and rght back
  std::copy(left.begin(), left.end(), vec.begin());
  std::copy(rght.begin(), rght.end(), vec.begin() + pivot_idx + 1);


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

