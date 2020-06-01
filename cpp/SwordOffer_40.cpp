#include<exception>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int data[], int length, int start, int end) {

	if (data == nullptr || length <= 0 || start < 0 || end >= length) {
		throw new exception("invalid parameter");
	}

	int index = start;
	swap(data[index], data[end]);

	int small = start - 1;

	for (index = start; index < end; ++index) {

		if (data[index] < data[end]) {
			small++;
			if (small != index) {
				swap(data[small], data[index]);
			}
		}
	}
	++small;
	swap(data[small], data[end]);
}

void GetLeastNumbers(int* input, int n, int* output, int k) {

	if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0) {
		return;
	}

	int start = 0;
	int end = n - 1;

	int index = Partition(input, n, start, end);
	while (index != k - 1) {

		if (index > k - 1) {
			end = index - 1;
			index = Partition(input, n, start, end);
		}

		else {
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}

	for (int i = 0; i < k; i++) {
		output[i] = input[i];
	}
}