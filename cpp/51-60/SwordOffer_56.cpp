unsigned int FindFirstBitIs1(int num) {

	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;
		indexBit++;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit) {
	num = num >> indexBit;
	return (num & 1);
}

void FindNumbersAppearOnce(int data[], int length, int* num1, int* num2) {

	if (data == nullptr || length <=1) {
		return;
	}

	int resultOr = 0;
	for (int i = 0; i < length; i++) {
		resultOr ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultOr);

	for (int j = 0; j < length; j++) {
		if (IsBit1(data[j], indexOf1)) {
			*num1 ^= data[j];
		}
		else {
			*num2 ^= data[j];
		}
	}
}