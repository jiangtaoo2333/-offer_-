#include<stdlib.h>

int compare(const void* arg1, const void* arg2) {
	return *(int*)arg1 - *(int*)arg2;
}

bool isContinuous(int* number, int length) {

	if (number == nullptr || length < 1) {
		return false;
	}

	qsort(number, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	for (int i = 0; i < length; i++) {
		if (number[i] == 0)
			numberOfZero++;
	}

	int small = numberOfZero;
	int large = small + 1;
	while (large < length) {
		if (number[small] == number[large])
			return false;
		numberOfGap = number[large] - number[small] - 1;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}