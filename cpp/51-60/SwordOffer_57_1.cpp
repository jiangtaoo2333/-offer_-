#include<vector>
using namespace std;

vector<vector<int> > foundcontinue(int sum) {

	vector<vector<int> > results;
	if (sum < 3) {
		return results;
	}

	int small = 1;
	int large = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + large;
	while (small < middle) {

		if (curSum == sum) {
			vector<int> result;
			results.push_back(result);
		}

		while (curSum > sum && small < middle) {
			curSum -= small;
			small++;
			if (curSum == sum) {
				vector<int> result;
				results.push_back(result);
			}
		}
		
		large++;
		curSum += large;
	}
}