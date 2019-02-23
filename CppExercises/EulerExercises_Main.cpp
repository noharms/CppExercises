
#include "pch.h"

#include <iostream>

#include "EulerExercises_Problem2.h"
#include "EulerExercises_Problem4.h"

void MainEulerExercises() {

	std::cout << "----------- Entering MainEulerExercises " << std::endl;

	//------------- Problem 2: https://projecteuler.net/problem=2
	std::cout << std::endl << "--- Euler Problem 2" << std::endl;
	const int count_until = 20;
	int result = EulerExerciseProblem2(count_until);
	std::cout << "Sum of all even Fibonacci numbers: " << result << std::endl << std::endl;

	//------------- Problem 4: https://projecteuler.net/problem=4
	std::cout << std::endl << "--- Euler Problem 4" << std::endl;
	const int max_digits = 2;
	result = EulerExerciseProblem4(max_digits);
	std::cout << "Largest Palindromic Number made from a product of two numbers, each smaller than " << pow(10,max_digits) << std::endl;
	std::cout << "is: " << result << std::endl << std::endl;


	std::cout << "----------- Leaving MainEulerExercises " << std::endl;

	return;
}