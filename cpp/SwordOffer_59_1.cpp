#include<queue>
using namespace std;

template<typename T>class QueueWithMax {

private:
	struct InternalData
	{
		T number;
		int index;
	};
	deque<InternalData> data;
	deque<InternalData> maximums;
	int currentIndex;

public:
	QueueWithMax() :currentIndex(0) {

	}
	void push_back(T number) {
		while (!maximums.empty() && number > maximums.back().number) {
			maximums.pop_back();
		}
		InternalData internalData = { number,currentIndex };
		maximums.push_back(internalData);
		data.push_back(internalData);
		++currentIndex;
	}

	void pop_front() {
		if (data.front().index == maximums.front().index) {
			maximums.pop_front();
		}
		data.pop_front();
	}

	T max() const {
		if (maximums.empty()) {
			throw new exception("queue is empty");
		}
		else {
			return maximums.front.number;
		}
	}
};