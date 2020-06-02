#include<string>
void PrintNumber(char* number) {

	bool isBegining0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; i++) {
		if (isBegining0 && number[i] != '0') {
			isBegining0 = false;
		}
		if (!isBegining0) {
			printf("%c", number[i]);
		}
	}
}

void PrintToMaxOfDigitsRecur(char* number, int length, int index) {

	if(index == length-1){
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++) {
		number[index + 1] = i + '0';
		PrintToMaxOfDigitsRecur(number, length,index + 1);
	}

}
void PrintToMaxOfDigits(int n) {

	if (n <= 0) {
		return;
	}

	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++) {
		number[0] = i + '0';
		PrintToMaxOfDigitsRecur(number, n, 0);
	}

	delete[] number;

}