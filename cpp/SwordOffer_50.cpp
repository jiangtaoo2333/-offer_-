char FindFirstRepeatingChar(char* pString) {

	if (pString == nullptr)
		return 0;

	const int tabelSize = 256;
	unsigned int hashTable[tabelSize];

	for (int i = 0; i < 256; i++) {
		hashTable[i] = 0;
	}

	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey)]++;
	pHashKey = pString;

	while (*pHashKey != '\0') {
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		pHashKey++;
	}

	return '\0';
}