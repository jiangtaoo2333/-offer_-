#include<stdio.h>
void PermutationCore(char* pStr, char* pBegin) {

	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	}

	else {
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {

			char temp = *pCh;
			*pCh = *pStr;
			*pStr = temp;

			PermutationCore(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pStr;
			*pStr = temp;

		}
	}
}


void Permutation(char* pStr) {

	if (pStr == nullptr) {
		return;
	}

	PermutationCore(pStr, pStr);
}