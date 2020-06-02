double PowerWithUnsignedInt(double base, unsigned int exponent) {
	double result = 1.0;
	for (unsigned int i = 1; i <= exponent; i++) {
		result *= base;
	}
	return result;
}

bool g_Invalid = false;

double Power(double base, int exponent) {

	g_Invalid = false;

	if (base - 0 < 0.00001 && exponent < 0) {
		g_Invalid = true;
		return 0.0;
	}
	
	unsigned int absExponent = (unsigned int)(exponent);

	if (exponent < 0) {
		absExponent = (unsigned int)(exponent);
	}

	double result = PowerWithUnsignedInt(base, absExponent);

	if (exponent < 0) {
		result = 1.0 / result;
	}
	return result;
}