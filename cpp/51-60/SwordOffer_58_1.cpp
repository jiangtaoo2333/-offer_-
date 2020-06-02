#include<string>
void Reverse(char* pBegin, char* pEnd) {

	if (pBegin == nullptr || pEnd == nullptr) {
		return;
	}

	while (pBegin <= pEnd) {
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}

void Reverse(char* pStr, int n) {

	if (pStr == nullptr) {
		return;
	}

	int nLength = static_cast<int>(strlen(pStr));
	char* pFirstStart = pStr;
	char* pFirstEnd = pStr + n - 1;
	char* pSecondStart = pStr + n;
	char* pSecondEnd = pStr + nLength;

	Reverse(pFirstStart, pFirstEnd);
	Reverse(pSecondStart, pSecondEnd);
	Reverse(pFirstStart, pSecondEnd);
}