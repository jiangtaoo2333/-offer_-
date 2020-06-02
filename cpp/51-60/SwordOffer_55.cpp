#include<algorithm>
#include<math.h>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

int TreeDepth(BinaryTreeNode* root) {

	if (root == nullptr) return 0;

	int left = TreeDepth(root->m_pLeft);
	int right = TreeDepth(root->m_pRight);

	return max(left, right) + 1;

}