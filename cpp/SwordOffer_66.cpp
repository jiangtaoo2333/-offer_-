#include<vector>
using namespace std;

void multiply(const vector<double>& array1, vector<double>& array2) {

	int length = array1.size();
	array2[0] = 1;
	for (int i = 1; i < length; i++) {
		array2[i] = array2[i - 1] * array1[i];
	}

	int temp = 1;
	for (int i = length - 2; i >= 0; i--) {
		temp *= array1[i + 1];
		array2[i] *= temp;
	}
}