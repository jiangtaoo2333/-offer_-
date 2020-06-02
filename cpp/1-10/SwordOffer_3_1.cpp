int countRange(const int* numbers, int length, int start, int end) {
	
	if (numbers == nullptr || length == 0) {
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; i++) {
		if (numbers[i] <= end && numbers[i] >= start) {
			count++;
		}
	}
	return count;
}

int getDuplication(const int* numbers, int length) {

	if (numbers == nullptr || length <= 0) {
		return -1;
	}

	int start = 1;
	int end = length - 1;

	while (start <= end) {
		int middle = (end - start) >> 1 + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start) {
			if (count > 1) {
				return middle;
			}
			else
				return -1;
		}
		if (count > (middle - start + 1)) {
			end = middle;
		}
		else {
			start = middle;
		}
	}
	return -1;
}