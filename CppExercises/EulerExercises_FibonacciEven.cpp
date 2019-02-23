

#include "pch.h"

#include "EulerExercises_FibonacciEven.h"

#include <iostream>



int EulerExerciseFibonacciEven(const int count_until) {

	// calculate the sum of all even Fibonacci numbers that are smaller than 4*10^6

		// 1. brute force method
	int old_num = 1;
	int new_num;
	int result = 0;
	for (new_num = 2; new_num < count_until; /*scytheMax is watching you here: 8) */) {
		if (new_num % 2 == 0) {
			result += new_num;
		}
		int tmp_old_num = old_num;
		old_num = new_num;
		new_num = tmp_old_num + new_num;
		std::cout << "Fibonacci number: " << new_num << std::endl;
	}

	// TODOs: check for int limits

	std::cout << "The result of summing all even Fibonacci nums < " << count_until;
	std::cout << "found by brute force is " << result;
	std::cout << "\n";
	

	return result;
}