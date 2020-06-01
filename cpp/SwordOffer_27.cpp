struct TreeNode
{
	double m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

void MirrorRecursively(TreeNode* pRoot) {

	if (pRoot == nullptr) {
		return;
	}

	if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr) {
		return;
	}

	TreeNode* temp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = temp;

	if (pRoot->m_pLeft) {
		MirrorRecursively(pRoot->m_pLeft);
	}
	if (pRoot->m_pRight) {
		MirrorRecursively(pRoot->m_pRight);
	}
	return;
}