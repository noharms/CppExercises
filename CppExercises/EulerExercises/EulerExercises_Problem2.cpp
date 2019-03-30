

#include "pch.h"

#include "EulerExercises_Problem2.h"

#include <iostream>


/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/
int EulerExerciseProblem2(const int count_until) {

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