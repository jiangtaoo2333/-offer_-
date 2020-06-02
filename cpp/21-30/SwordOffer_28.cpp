struct TreeNode
{
	double m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};


bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {

	if (pRoot1 == nullptr && pRoot2 == nullptr) {
		return true;
	}

	if (pRoot1 == nullptr || pRoot2 == nullptr) {
		return false;
	}

	if (pRoot1->m_nValue != pRoot2->m_nValue) {
		return false;
	}

	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetrical(TreeNode* pRoot) {

	if (pRoot == nullptr) {
		return true;
	}
	else {
		return isSymmetrical(pRoot, pRoot);
	}
}