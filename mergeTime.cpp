#include <iostream>

// This code was mainly copied from my sorting assignment for CS290 at Clackamas Community College
// Other than the main function
// https://docs.google.com/document/d/1D5M7uSyknAyoMroaDhLS90I_8kBa9eL-yO2N5VuxsNI/edit?usp=sharing

void merger(int sortArray[], int low, int  mid, int high) {
	int* temp = new int[high - low + 1];
	int i = low, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		if (sortArray[i] <= sortArray[j])
			temp[k++] = sortArray[i++];
		else
			temp[k++] = sortArray[j++];
	}

	while (i <= mid)
		temp[k++] = sortArray[i++];

	while (j <= high)
		temp[k++] = sortArray[j++];

	for (k = 0, i = low; i <= high; ++i, ++k)
		sortArray[i] = temp[k];

	delete[]temp;
}

void mergeSort(int array[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;

		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);

		merger(array, low, mid, high);
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
		len = (i + 1) * 10000;
		std::cout << len << "\t\t";
		srand(time(NULL));
		for (int j = 0; j < len; j++)
			randArray[j] = rand() % len;

		// Do Time calculations
		startTime = clock();
		mergeSort(randArray, 0, len - 1);
		endTime = clock();

		total = (endTime - startTime) / (CLOCKS_PER_SEC / 1000);

		std::cout << total << "\n";
		len++;
	}
	return 0;
}