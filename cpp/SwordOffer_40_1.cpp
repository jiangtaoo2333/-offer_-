#include<set>
#include<vector>
using namespace std;

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k) {

	leastNumbers.clear();
	if (k < 1 || data.size() < k) {
		return;
	}

	vector<int>::const_iterator iter = data.begin();

	for (; iter != data.end(); ++iter) {
		if (leastNumbers.size() < k) {
			leastNumbers.insert(*iter);
		}
		else
		{
			setIterator iterGreatest = leastNumbers.begin();
			if (*iter < *iterGreatest) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}