int MoreThanHalfNumber(int* numbers, int length) {

	int result = numbers[0];
	int times = 1;
	
	for (int i = 1; i < length; i++) {

		if (times == 0) {
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result) {
			times++;
		}
		else{
			times--;
		}
	}
	return result;
}