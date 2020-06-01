class CharStatistic {

public:
	CharStatistic() :index(0) {
		for (int i = 0; i < 256; i++) {
			occurrence[i] = -1;
		}
	}

	void Insert(char ch) {
		if (occurrence[ch] == -1) {
			occurrence[ch] == index;
		}
		else if (occurrence[ch] > -1) {
			occurrence[ch] == -2;
		}
		index++;
	}

	char FirstAppearingOnce() {
		int minIndex = -3;
		char result = '\0';
		for (int i = 0; i < 256; i++) {
			if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
				minIndex = occurrence[i];
				result = (char)i;
			}

		}
		return result;
	}
private:
	int occurrence[256];
	int index;
};