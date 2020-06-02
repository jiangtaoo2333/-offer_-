int numberOfOne(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			count++;
		}
		flag = flag << 1;
	}
	return 1;
}

int numberOfOne_(int n) {
	int count = 0;
	while (n) {
		count++;
		n = n & (n - 1);
	}
	return count;
}