struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

#include<vector>
using namespace std;

void FindPathCore(BinaryTreeNode* pRoot,int expectedSum,int currentSum,vector<int> path) {
	
	if (pRoot == nullptr) {
		return;
	}

	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;

	if (currentSum == expectedSum && isLeaf) {
		for (vector<int>::iterator iter = path.begin(); iter < path.end(); iter++) {
			printf("%d", *iter);
		}
	}

	if (pRoot->m_pLeft != nullptr) {
		FindPathCore(pRoot->m_pLeft, expectedSum, currentSum, path);
	}

	if (pRoot->m_pRight != nullptr) {
		FindPathCore(pRoot->m_pRight, expectedSum, currentSum, path);
	}

	path.pop_back();
}
void FindPath(BinaryTreeNode* pRoot, int expectedSum) {

	if (pRoot == nullptr) {
		return;
	}

	vector<int> path;
	int currentSum = 0;
	FindPathCore(pRoot, expectedSum, currentSum, path);
}