
#include "pch.h"

#include <iostream>

#include "EulerExercises_Problem2.h"

void MainEulerExercises() {

	std::cout << "----------- Entering MainEulerExercises " << std::endl;

	const int count_until = 20;
	int result = EulerExerciseFibonacciEven(count_until);
	std::cout << "Sum of all even Fibonacci numbers: " << result << std::endl;



	std::cout << "----------- Leaving MainEulerExercises " << std::endl;

	return;
}