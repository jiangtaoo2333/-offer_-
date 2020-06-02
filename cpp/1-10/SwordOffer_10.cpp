

long long Fibnocci(unsigned n) {
	int results[2] = { 0,1 };
	if (n < 2) {
		return results[n];
	}

	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;

	for (unsigned int i = 2; i <= n; i++) {
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}
	return fibN;
}