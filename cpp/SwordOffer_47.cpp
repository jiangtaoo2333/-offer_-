#include<algorithm>
using namespace std;


int getMaxValue(const int* values, int rows, int cols) {

	if (values == nullptr || rows <= 0 || cols <= 0) {
		return 0;
	}

	int** maxValues = new int* [rows];
	for (int i = 0; i < rows; i++) {
		maxValues[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			int up = 0;
			int left = 0;
			if (i > 0) {
				up = maxValues[i-1][j];
			}
			if (j > 0) {
				left = maxValues[i][j - 1];
			}

			maxValues[i][j] = max(up, left) + values[i * cols + j];
		}
	}

	return maxValues[rows - 1][cols - 1];
}