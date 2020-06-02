#include<queue>
using namespace std;

class Mystack {
private:
	queue<int> q;
public:
	Mystack() {

	}

	void push(int x) {
		queue<int> temp;
		while (!q.empty()) {
			temp.push(q.front());
			q.pop();
		}
		q.push(x);
		while (!temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
	}

	int pop() {
		int top = q.front();
		q.pop();
		return top;
	}

	int top() {
		return q.front();
	}

	bool empty() {
		return q.empty();
	}
};