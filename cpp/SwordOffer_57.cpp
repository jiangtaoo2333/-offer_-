bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int num2) {
	
	bool Found = false;
	
	if (data == nullptr || length <= 1) {
		return Found;
	}

	int left = 0;
	int right = length - 1;

	while (left < right) {

		int curSum = data[left] + data[right];
		if (curSum < sum)
			left++;
		else if (curSum > sum)
			right--;
		else
			true;
	}

	return Found;
}