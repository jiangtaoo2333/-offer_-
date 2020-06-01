#include<vector>
using namespace std;

bool Find(vector<vector<int>> matrix, int number){

	bool found = false;
	int rows = matrix.size();
	int columns = matrix[0].size();
	int row = 0;
	int column = columns - 1;

	while (row<rows&&column>=0) {
		if (matrix[row][column] == number) {
			found = true;
			break;
		}
		else if (matrix[row][column] > number) {
			column--;
		}
		else {
			row++;
		}
	}
	return found;
}