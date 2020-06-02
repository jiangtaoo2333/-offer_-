int MaxDiff(const int* numbers, unsigned int length) {

	if (numbers == nullptr && length < 2) {
		return 0;
	}

	int min = numbers[0];
	int maxDiff = numbers[1] - numbers[0];

	for (int i = 2; i < length; i++) {
		if (numbers[i - 1] < min)
			min = numbers[i - 1];

		if (numbers[i] - min < maxDiff)
			maxDiff = numbers[i] - min;
	}

	return maxDiff;
}