#include <iostream>
#include <time.h>

// This code was mainly copied from my sorting assignment for CS290 at Clackamas Community College
// Other than the main function
// https://docs.google.com/document/d/1D5M7uSyknAyoMroaDhLS90I_8kBa9eL-yO2N5VuxsNI/edit?usp=sharing

void insertionsort(int array[], int size) {
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	return;
}

int main() {
	// Creating variables
	int const MAX_SIZE = 100000;
	int startTime = 0;
	int endTime = 0;
	int total = 0;
	int randArray[MAX_SIZE] = { 0 };
	int len = 1;

	std::cout << "Length\t\tTime(Milliseconds)\n";

	for (int i = 0; i < 10; i++) {
		// Creating random array
		len = (i+1) * 10000;
		std::cout << len << "\t\t";
		srand(time(NULL));
		for (int j = 0; j < len; j++)
			randArray[j] = rand() % len;

		// Do Time calculations
		startTime = clock();
		insertionsort(randArray, len);
		endTime = clock();

		total = (endTime - startTime) / (CLOCKS_PER_SEC/1000);

		std::cout << total << "\n";
		len++;
	}
	return 0;
}