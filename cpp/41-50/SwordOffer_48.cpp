#include<string>
using namespace std;


int longestSubString(const string& str) {

	int curLength = 0;
	int maxLength = 0;

	int* position = new int[26];
	for (int i = 0; i < 26; i++) {
		position[i] = -1;
	}

	for (int i = 0; i < str.length(); i++) {

		int preIndex = position[str[i] - 'a'];
		if (preIndex<0 || i - preIndex>curLength) {
			curLength++;
			if (curLength > maxLength) {
				maxLength = curLength;
			}
		}

		else {
			curLength = i - preIndex;
		}
	}
	delete[] position;
	return maxLength;

}