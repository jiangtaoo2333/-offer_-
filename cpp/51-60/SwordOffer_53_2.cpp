int GetNumberSameAsIndex(const int* data, int length) {

	if (data == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = (left + right) >> 1;
		if (data[middle] == middle) {
			return middle;
		}
		else if (data[middle] > middle) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return -1;
}