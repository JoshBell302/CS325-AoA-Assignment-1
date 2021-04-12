#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

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
	// Creating values
	int const size = 200;
	std::string fromFile[size];
	std::string line;
	std::string compile;
	char charLine[255];
	int count = 0;
	int low = 0;

	// Reading from data.txt file and coping vvalues and placing into fromFile
	std::ifstream file("data.txt");
	if (file.is_open()) {
		while (std::getline(file, line)) {
			fromFile[count] = line;
			count++;
		}

		file.close();
	}
	else
		std::cout << "Could not load file";

	// Reading file line by line
	for (int index = 0; index < count; index++) {
		int j = 0;
		int len = 0;
		int intArray[size] = { 0 };
		strcpy(charLine, fromFile[index].c_str());

		// Obtaining length of charLine array
		while (charLine[len] != 0)
			len++;

		// Converting charLine to intArray
		for (int a = 0; a < len; a++) {
			if (charLine[a] != '0') {
				if (charLine[a] != ' ') {
					if (charLine[a + 1] == ' ') {
						intArray[j] = int(charLine[a]) - 48;
						j++;
					}
					else {
						compile = "";
						compile += charLine[a];
						compile += charLine[a + 1];
						a++;
						intArray[j] = stoi(compile);
						j++;
					}
				}
			}
		}

		// Grabbing length of intArray
		len = intArray[0];

		// Deleting length value from list to be sorted
		for (int i = 0; i < len + 1; i++)
			intArray[i] = intArray[i + 1];

		mergeSort(intArray, low, len - 1);

		// Displaying result of sorting
		for (int i = 0; i < len; i++)
			std::cout << intArray[i] << " ";
		std::cout << "\n";

	}
	return 0;
}