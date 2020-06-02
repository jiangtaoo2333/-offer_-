#include<string>

const int g_MaxNumberOfLength = 10;
char* g_Str1 = new char[g_MaxNumberOfLength * 2 + 1];
char* g_Str2 = new char[g_MaxNumberOfLength * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2) {

	strcpy(g_Str1, *(const char**)strNumber1);
	strcat(g_Str1, *(const char**)strNumber2);

	strcpy(g_Str2, *(const char**)strNumber2);
	strcat(g_Str2, *(const char**)strNumber1);

	return strcmp(g_Str1, g_Str2);
}

void MinNumber(int* numbers, int length) {

	if (numbers == nullptr || length <= 0) {
		return;
	}

	char** strNumbers = (char**)(new int[length]);

	for (int i = 0; i < length; i++) {
		strNumbers[i] = new char[g_MaxNumberOfLength + 1];
		sprintf(strNumbers[i],"%d",numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);
}