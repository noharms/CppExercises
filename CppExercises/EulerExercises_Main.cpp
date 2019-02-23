
#include "pch.h"

#include <iostream>

#include "EulerExercises_Problem2.h"

void MainEulerExercises() {

	std::cout << "----------- Entering MainEulerExercises " << std::endl;

	//------------- Problem 2: https://projecteuler.net/problem=2
	const int count_until = 20;
	int result = EulerExerciseProblem2(count_until);
	std::cout << "Sum of all even Fibonacci numbers: " << result << std::endl;

	//------------- Problem 4: https://projecteuler.net/problem=4
	// TODO


	std::cout << "----------- Leaving MainEulerExercises " << std::endl;

	return;
}