#include<cstring>
#include <stdlib.h>

int PowerBase10(unsigned int n) {
	int result = 1;
	for (unsigned int i = 0; i < n; i++) {
		result *= 10;
	}
	return result;
}

int NumberOf1(const char* strN) {

	if (strN == nullptr||*strN < '0'||*strN>'9'||*strN=='\0') {
		return 0;
	}

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN);

	if (length == 1 && first == 0) {
		return 0;
	}
	if (length == 1 && first == 1) {
		return 1;
	}

	int numFirstDigit = 0;
	if (first > 1) {
		numFirstDigit = PowerBase10(length - 1);
	}
	else {
		numFirstDigit = atoi(strN + 1) + 1;
	}

	int numOtherDigit = 0;
	numOtherDigit = first * (length - 1) * PowerBase10(length - 2);

	int numRecursive = 0;
	numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigit + numRecursive;


}