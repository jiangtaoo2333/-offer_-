#include<queue>
#include<vector>
using namespace std;

struct BinaryTreeNode {

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

};

vector<vector<int>> levelOrder(BinaryTreeNode* root) {

	vector<vector<int>> result;
	if (root == nullptr) {
		return result;
	}

	queue<BinaryTreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		vector<int> temp;
		int num = q.size();
		for (int i = 0; i < num; i++) {
			BinaryTreeNode* pNode = q.front();
			q.pop();
			temp.push_back(pNode->m_nValue);
			if (pNode->m_pLeft) {
				q.push(pNode->m_pLeft);
			}
			if (pNode->m_pRight) {
				q.push(pNode->m_pRight);
			}
		}
		result.push_back(temp);
	}
	return result;
}