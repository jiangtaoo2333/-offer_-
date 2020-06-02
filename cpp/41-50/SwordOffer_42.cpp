#include <iostream>
#include <Windows.h>
using namespace std;

#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000

int FindGreatestOfSubArray(int* pData, int nLength) {

	if (pData == nullptr || nLength == 0) {
		return;
	}

	int greatest = INT_MIN;
	int sum = pData[0];

	for (int i = 1; i < nLength; i++) {
		sum = max(sum+pData[i], pData[i]);
		greatest = max(sum, greatest);
	}

	return greatest;
}