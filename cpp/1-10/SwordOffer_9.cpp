#include<stack>
using namespace std;
class MyQueue {
private:
	stack<int> stack1;
	stack<int> stack2;

public:
	MyQueue() {

	}

	void adjust() {
		while (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
	}

	void push(int x) {
		stack1.push(x);
	}

	int pop() {
		adjust();
		int x = stack2.top();
		stack2.pop();
		return x;
	}

	int peek() {
		adjust();
		return stack2.top();
	}

	bool empty() {
		return stack1.empty() && stack2.empty();
	}
	
};