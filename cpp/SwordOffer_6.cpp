#include<stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void printReverse(ListNode* pHead) {
	                         
	stack<ListNode*> nodes;

	if (pHead == nullptr) {
		return;
	}

	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty()) {
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}