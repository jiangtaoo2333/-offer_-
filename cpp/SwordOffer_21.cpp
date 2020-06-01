void ReorderOddEven(int* pData, unsigned int length) {

	if (pData == nullptr || length == 0) {
		return;
	}

	int *pBegin = pData;
	int* pEnd = pData + length - 1;

	while (pBegin < pEnd) {

		while (pBegin < pEnd && (*pBegin & 0x1) != 0) {
			pBegin++;
		}

		while (pEnd > pBegin && (*pEnd & 0x1) == 1) {
			pEnd--;
		}

		if (pBegin < pEnd) {
			int temp = *pEnd;
			*pEnd = *pBegin;
			*pBegin = temp;
		}
	}
}