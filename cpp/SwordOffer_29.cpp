
void PrintNum(int x) {
	return;
}

void PrintMatrixInCircle(int** number, int columns, int rows, int start) {

	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i < endX; i++) {
		PrintNum(number[start][i]);
	}

	if (start < endY) {
		for (int i = start + 1; i <= endY; i++) {
			PrintNum(number[i][endX]);
		}
	}

	if (start < endX && start < endY) {
		for (int i = endX - 1; i >= start; i--) {
			PrintNum(number[endY][i]);
		}
	}

	if (start < endX && start < endY - 1) {
		for (int i = endY - 1; i >= start + 1; i--) {
			PrintNum(number[i][start]);
		}
	}
}

void PrintMatrix(int** number, int columns, int rows) {

	if (number == nullptr || columns == 0 || rows == 0) {
		return;
	}

	int start = 0;

	while (columns >= start * 2 && rows >= start * 2) {
		PrintMatrixInCircle(number, columns, rows, start);
		start += 1;
	}
}