
#include "pch.h"

#include <iostream>
#include <vector>

#include "EulerExercises_Problem2.h"
#include "EulerExercises_Problem4.h"
#include "EulerExercises_Problem8.h"
#include "EulerExercises_Problem15.h"

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

	//------------- Problem 8: https://projecteuler.net/problem=8
	std::cout << std::endl << "--- Euler Problem 8" << std::endl;	
	const int adjacent_digits_to_consider = 4;	
	long long largest_product = EulerExerciseProblem8(adjacent_digits_to_consider);
	std::cout << "Considering " << adjacent_digits_to_consider << " adjacent digits" << std::endl;
	std::cout << "the largest product of the digits in the given 1000-digit number (see src-file)" << std::endl;
	std::cout << "is: " << largest_product << std::endl;	

	//------------- Problem 15: https://projecteuler.net/problem=15
	std::cout << std::endl << "--- Euler Problem 15" << std::endl;
	const int dim_grid = 2;
	int found_downrightroutes_through_grid = EulerExerciseProblem15(dim_grid);
	std::cout << "Found " << found_downrightroutes_through_grid;
	std::cout << " possible routes through the " << dim_grid << "x" << dim_grid << " grid." << std::endl;

	//--------------------------
	std::cout << std::endl << std::endl;
	std::cout << "----------- Leaving MainEulerExercises " << std::endl;

	return;
}