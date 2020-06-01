#include<queue>
using namespace std;

struct BinaryTreeNode {

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

};

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot) {

	if (!pTreeRoot) {
		return;
	}

	queue<BinaryTreeNode*> queueTreeNode;

	queueTreeNode.push(pTreeRoot);

	while (queueTreeNode.size())
	{
		BinaryTreeNode* pNode = queueTreeNode.front();
		queueTreeNode.pop();

		printf("%d", pNode->m_nValue);

		if (pNode->m_pLeft) {
			queueTreeNode.push(pNode->m_pLeft);
		}

		if (pNode->m_pRight) {
			queueTreeNode.push(pNode->m_pRight);
		}
	}
}
