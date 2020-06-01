void FindNumberAppearingOnce(int numbers[], int length,int* number) {

	if(number == nullptr || length <= 0) {
		return;
	}

	int bitSum[32] = { 0 };

	for (int i = 0; i < length; i++) {

		int bitMask = 1;
		for (int j = 31; j >= 0; i--) {
			int bit = bitMask & numbers[i];
			if (bit != 0)
				bitSum[j]++;
			bitMask <<= 1;
		}
	}

	*number = 0;
	for (int i = 0; i < 32; i++) {
		*number <<= 1;
		*number += bitSum[i] % 3;
	}
}