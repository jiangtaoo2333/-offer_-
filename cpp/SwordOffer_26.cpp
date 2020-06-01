struct TreeNode
{
	double m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};


bool Equal(double num1, double num2) {

	if ((num1 - num2) > -0.00000001 || (num1 - num2) < 0.00000001) {
		return true;
	}
	else {
		return false;
	}
}

bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
	
	if (pRoot2 == nullptr) {
		return true;
	}

	if (pRoot1 == nullptr) {
		return false;
	}

	if (!Equal(pRoot1->m_nValue, pRoot2->m_nValue)) {
		return false;
	}

	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);

}

bool HasSubTree(TreeNode* pRoot1, TreeNode* pRoot2) {

	bool result = false;

	if (pRoot2 == nullptr) {
		return true;
	}

	if (pRoot1 == nullptr) {
		return false;
	}

	if (Equal(pRoot1->m_nValue, pRoot2->m_nValue)) {
		result = DoesTree1HaveTree2(pRoot1, pRoot2);
	}

	if (!result) {
		result = HasSubTree(pRoot1->m_pLeft, pRoot2);
	}

	if (!result) {
		result = HasSubTree(pRoot1->m_pRight, pRoot2);
	}

	return result;
}