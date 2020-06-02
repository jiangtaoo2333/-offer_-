#include<algorithm>
#include<math.h>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool IsBalanced(BinaryTreeNode* pRoot, int* depth) {

	if (pRoot == nullptr) {
		*depth = 0;
		return true;
	}

	int left = 0;
	int right = 0;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = max(left, right) + 1;
			return true;
		}
		else
			return false;
	}
	return false;
}