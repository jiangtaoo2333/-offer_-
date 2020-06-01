#include<vector>
#include<deque>

using namespace std;


vector<int> maxInWindows(const vector<int>& num, unsigned int size) {

	vector<int> result;
	deque<int> index;
	for (unsigned int i = 0; i < size; i++) {
		while (!index.empty() && num[i] >= num[index.back()]) {
			index.pop_back();
		}
		index.push_back(i);
	}
	for (unsigned int i = size; i < num.size(); i++) {

		result.push_back(num[index.front()]);

		while (!index.empty() && num[i] >= num[index.back()]) {
			index.pop_back();
		}
		index.push_back(i);

		if (!index.empty() && (int)(i - index.front()) >= size) {
			index.pop_front();
		}
	}

	result.push_back(num[index.front()]);

	return result;
}