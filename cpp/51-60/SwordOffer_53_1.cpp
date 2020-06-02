int GetMissingNumber(const int* data, int length) {

	if (data == nullptr || length < 0)
		return -1;
	int start = 0;
	int end = length - 1;
	while (start <= end) {
		int middle = (start + end) >> 2;
		if (data[middle] > middle) {
			if ((data[middle - 1] == middle - 1 && middle > 0) || middle == 0)
				return middle;
			else
				end = middle - 1;
		}
		else
			start = middle + 1;
		
	}
	if (start == length) {
		return length;
	}

}