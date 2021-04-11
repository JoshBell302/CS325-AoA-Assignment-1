#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This code was mainly copied from my sorting assignment for CS290 at Clackamas Community College
// Other than the main function

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
	int const size = 200;
	string fromFile[size];
	string line;
	string compile;
	char charLine[255];
	int count = 0;

	ifstream file("data.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			fromFile[count] = line;
			count++;
		}

		file.close();
	}
	else
		cout << "Could not load file";

	for (int index = 0; index < count; index++) {
		int j = 0;
		int len = 0;
		int intArray[size] = { 0 };
		strcpy_s(charLine, 255, fromFile[index].c_str());

		while (charLine[len] != 0)
			len++;

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
		len = 0;
		while (intArray[len] != 0)
			len++;

		insertionsort(intArray, len);

		for (int i = 0; i < len; i++)
			cout << intArray[i] << " ";
		cout << endl;

	}
	return 0;
}