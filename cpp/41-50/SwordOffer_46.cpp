#include<string>
using namespace std;

int GetTranslationCount(const string&);

int GetTranslationCount(int number) {

	if (number < 0)
		return 0;

	string numberInstring = to_string(number);
	return GetTranslationCount(numberInstring);
}

int GetTranslationCount(const string& number) {

	int length = number.length();
	int* counts = new int[length];
	int count = 0;

	for (int i = length - 1; i >= 0; i--) {

		count = 0;
		if (i < length - 1) {
			count = counts[i + 1];
		}
		else {
			count = 1;
		}

		if (i < length - 1) {
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int convert = digit1 * 10 + digit2;
			if (convert >= 10 && convert <= 25) {
				if (i < length - 2) {
					count += counts[i + 2];
				}
				else {
					count += 1;
				}
			}

			counts[i] = count;
		}
	}
}