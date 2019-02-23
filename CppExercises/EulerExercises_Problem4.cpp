
#include "pch.h"

#include "EulerExercises_Problem4.h"

#include <iostream>
#include <vector>
#include <algorithm>   // would offer the reverse function to flip a vector .. but found another solution
#include <stdio.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
int EulerExerciseProblem4(const int max_digits) {
	
	const int max_factor = (int)(pow(10, max_digits) + 0.5);  // power for integers

	int max_palindrome_number = 0;

	for (int i = 1; i < max_factor; ++i) {
		for (int j = 1; j < max_factor; ++j) {
			int candidate = i * j;
			// for debug
			// std::cout << "Checking candidate number " << candidate << std::endl;
			if (candidate > max_palindrome_number && IsPalindrome(candidate)) { // TODO: check if 2nd condition is evaluated if 1st fails... would want that here
				max_palindrome_number = candidate;
				// for debug
				// std::cout << "---> new largest palindrome number " << candidate << std::endl;
			}
			// for debug : keypress
			// std::cin.ignore();
		}
	}

	return max_palindrome_number;
}

bool IsPalindrome(int num) {

	bool ispalindrome = true;
	std::vector<int> digits;

	if (abs(num) > 9) { // if num < 10, we always have a palindrome
		int ndigits = TurnNumberToVectorOfDigits(digits, num);
		
		// go through the digits and check if they are palindromic
		for (int i = 0; i < floor(ndigits / 2); ++i) {
			if (digits[i] != digits[ndigits - 1 - i]) {
				ispalindrome = false;
				break;
			}
		}
	}

	return ispalindrome;
}

int GetNumDigits(int num) {

	int ndigits = 0;

	if (num < 0) {
		num *= -1;
	}

	// increment ndigits for every division by 10 that does not lead to 0-result
	while (num) {
		++ndigits;
		num /= 10;
	}

	return ndigits;
}


int TurnNumberToVectorOfDigits(std::vector<int>& vec_digits, int num) {

	int ndigits = GetNumDigits(num);
	
	// turn the number into a vector of digits
	for (int i = 0; i < ndigits; ++i) {
		int digit = num % 10;
		vec_digits.insert(vec_digits.begin(), digit);
		num /= 10;
	}
	
	// debug
	/*std::cout << "Num " << num << " as digits: " << std::endl;
	for (int i = 0; i < ndigits; ++i) {
		std::cout << "digit " << i << ": " << vec_digits[i] << std::endl;
	}*/

	return ndigits;
}