#include<stack>
using namespace std;

struct BinaryTreeNode {

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* kthSmallestNode(BinaryTreeNode* root, int k) {
		
	if (root == nullptr || k < 0) {
		return nullptr;
	}

	stack<BinaryTreeNode*> stack;
	BinaryTreeNode* pNode = root;

	if (pNode || !stack.empty()) {

		if (pNode) {
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else {
			pNode = stack.top();
			stack.pop();
			k--;
			if (k == 0) {
				return pNode;
			}
			pNode = pNode->m_pRight;
		}
	}

	return 0;
}