int GetFirstK(int* data, int length, int k, int start, int end) {

	if (start > end)
		return -1;
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k) {
		if (middleIndex == 0 || (middleIndex> 0&&data[middleIndex - 1] != k)) {
			return middleIndex;
		}
		end = middleIndex - 1;
	}
	else if (middleData > k) {
		end = middleIndex - 1;
	}
	else {
		start = middleIndex + 1;
	}
}
int GetLastK(int* data, int length, int k, int start, int end) {

	if (start > end)
		return -1;
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k) {
		if (middleIndex == length-1 || (middleIndex < length-1 && data[middleIndex + 1] != k)) {
			return middleIndex;
		}
		end = middleIndex - 1;
	}
	else if (middleData > k) {
		end = middleIndex - 1;
	}
	else {
		start = middleIndex + 1;
	}

}