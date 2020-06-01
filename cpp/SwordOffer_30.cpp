#include<stack>

template<typename T>
class StackWithMin {
	stack<T> m_data;
	stack<T> m_min;
	void push(const T);
	const T& min();
};

template<typename T>
void StackWithMin<T>::push(const T value) {

	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.pop()) {
		m_min.push(value);
	}
	else {
		m_min.push(m_min.top());
	}
}

template<typename T>
const T& StackWithMin<T>::min() {

	return m_min.top();

}
