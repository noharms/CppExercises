
#include "pch.h"

#include "EulerExercises_Problem8.h"

#include <vector>
#include <string>
#include <iostream>

/*

https://projecteuler.net/problem=8

The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?


Ideas:

	- this number is too large for int  (int limits +-2^32 = ca 10^9)
	  -> use array for the digits
	(array of int for efficieny; on embedded one could think about using unsigned char
	 here to save memory)

	-  the product of adjacent digits can get larger than int  as well
	--> lets use long long (+-2^63 = ca 10^18) and prohibit to use more than 18 adjacent digits

	- let's cache the intermediate results: when we proceed by one digit we do not always need to
	  recalculate the whole product ! if we store the product we can simply divide by the removed digit and 
	  multiply by the newly added digit to get the new product including the new digit

	  -> ACHTUNG: if a 0 is swiped out, we have to recalculate in any case ! we cannot divide by and the knowledge
	              of the product without the 0 is not there !

*/
long long EulerExerciseProblem8(const int adjacent_digits_to_consider) {

	if (adjacent_digits_to_consider > 18) {
		return -1;
	}
	
	std::vector<int> large_number(GetHardcodedLargeNumber());

	// calculate the product of the first adjacent digits	
	long long current_product = 1;
	std::vector<int>::iterator it_1;
	for (it_1 = large_number.begin(); it_1 < large_number.begin() + adjacent_digits_to_consider; ++it_1) {
		int curr_digit = *it_1;
		current_product *= curr_digit;			
	}
	std::vector<int>::iterator lastindex_maximumproductdigits = it_1 - 1;

	long long largest_product = 0;
	for (std::vector<int>::iterator it = large_number.begin() + adjacent_digits_to_consider; it != large_number.end(); ++it) {  // alternative: using iterators.. 
	//for (int i = adjacent_digits_to_consider; i < large_number.size(); ++i) {   // -> gives warning because size() returns size_t type
	//for (size_t i = adjacent_digits_to_consider; i < large_number.size(); ++i) {   // -> gives warning because size() returns size_t type	
		int swiped_out_digit = *(it - adjacent_digits_to_consider);
		int swiped_in_digit = *it;		
		if (swiped_out_digit != 0) {
			current_product /= swiped_out_digit;
			current_product *= swiped_in_digit;
		} else { // if a zero is swiped out, we have to recompute over all relevant digits
			current_product = 1;
			for (int j = 0; j < adjacent_digits_to_consider; ++j) {
				current_product *= *(it - j);
			}
		}
		if (current_product > largest_product) {
			largest_product = current_product;
			lastindex_maximumproductdigits = it;
		}
	}
	
	// get the digits whose product is the largest
	std::vector<int> digits_largest_product;	
	for (std::vector<int>::iterator it = lastindex_maximumproductdigits - adjacent_digits_to_consider + 1; it <= lastindex_maximumproductdigits; ++it) {
		digits_largest_product.push_back(*it);
	}

	std::cout << "Digits whose product is the largest: " << std::endl;
	for (std::vector<int>::iterator it = digits_largest_product.begin(); it != digits_largest_product.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return largest_product;
}

std::vector<int> GetHardcodedLargeNumber() {

	std::string large_number_as_string =
		"73167176531330624919225119674426574742355349194934"
		"96983520312774506326239578318016984801869478851843"
		"85861560789112949495459501737958331952853208805511"
		"12540698747158523863050715693290963295227443043557"
		"66896648950445244523161731856403098711121722383113"
		"62229893423380308135336276614282806444486645238749"
		"30358907296290491560440772390713810515859307960866"
		"70172427121883998797908792274921901699720888093776"
		"65727333001053367881220235421809751254540594752243"
		"52584907711670556013604839586446706324415722155397"
		"53697817977846174064955149290862569321978468622482"
		"83972241375657056057490261407972968652414535100474"
		"82166370484403199890008895243450658541227588666881"
		"16427171479924442928230863465674813919123162824586"
		"17866458359124566529476545682848912883142607690042"
		"24219022671055626321111109370544217506941658960408"
		"07198403850962455444362981230987879927244284909188"
		"84580156166097919133875499200524063689912560717606"
		"05886116467109405077541002256983155200055935729725"
		"71636269561882670428252483600823257530420752963450"
	;
	const int n_digits_largenumber = large_number_as_string.size();

	std::cout << "Large number has " << n_digits_largenumber << "digits " << std::endl;

	// transform string to vector of digits
	std::vector<int> digits;
	for (std::string::iterator it = large_number_as_string.begin(); it != large_number_as_string .end(); ++it) {
		int digit = (int) (*it) - (int) '0';  
		// when casting to int, cpp convert chars to integers according to their ascii code
		// digits 0-9 have sequential in ascii codes
		// -> the above should be equivalent to atoi(&large_number_as_string[i]);
		digits.push_back(digit);
	}

	return digits;
}