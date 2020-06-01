bool VerifySequenceOfBST(int sequence[], int length) {

	if (sequence == nullptr || length == 0) {
		return false;
	}

	int root = sequence[length - 1];

	int i = 0;
	for (; i < length - 1; i++) {
		if (sequence[i] > root) {
			break;
		}
	}

	int j = i;
	for (; j < length - 1; j++) {
		if (sequence[j] < root) {
			return false;
		}
	}

	bool left = false;
	if (i > 0) {
		left = VerifySequenceOfBST(sequence, i);
	}

	bool right = false;
	if (j < length - 1) {
		right = VerifySequenceOfBST(sequence + i, length - i - 1);
	}

	return left && right;
}