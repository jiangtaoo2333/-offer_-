#include<list>
using namespace std;

int lastRemain(unsigned int n, unsigned int m) {

	if (n < 1 || m < 1) {
		return -1;
	}

	unsigned int i = 0;
	list<int> numbers;
	for (i = 0; i < n; i++) {
		numbers.push_back(i);
	}

	list<int>::iterator current = numbers.begin();

	while (numbers.size() > 1) {

		for (int i = 1; i <= m; i++) {
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}

		list<int>::iterator next = current++;
		if (next == numbers.end())
			next = numbers.begin();

		numbers.erase(current);
		current = next;

	}

	return *(current);
}