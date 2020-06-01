#include<stack>
using namespace std;

struct BinaryTreeNode {

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

};

void Print(BinaryTreeNode* pRoot) {

	if (pRoot == nullptr) {
		return;
	}

	stack<BinaryTreeNode*> levels[2];
	int current = 0;
	int next = 1;

	levels[current].push(pRoot);
	while (!levels[current].empty()) {

		BinaryTreeNode* pNode = levels[current].top();
		levels[current].pop();

		printf("%d", pNode->m_nValue);

		if (current == 0) {
			if (pNode->m_pLeft != nullptr) {
				levels[next].push(pNode->m_pLeft);
			}
			if (pNode->m_pRight != nullptr) {
				levels[next].push(pNode->m_pRight);
			}
		}

		else {
			if (pNode->m_pRight != nullptr) {
				levels[next].push(pNode->m_pRight);
			}
			if (pNode->m_pLeft != nullptr) {
				levels[next].push(pNode->m_pLeft);
			}
		}

		if (levels[current].empty()) {
			printf("\n");
			current = 1 - current;
			next = 1 - next;
		}
	}
}