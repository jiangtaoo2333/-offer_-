struct BinaryTreeNode {

	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Convert(BinaryTreeNode* pNode, BinaryTreeNode** pLastNode) {

	if (pNode == nullptr) {
		return;
	}

	BinaryTreeNode* pCurrent = pNode;
	if (pCurrent->m_pLeft != nullptr) {
		Convert(pCurrent->m_pLeft, pLastNode);
	}

	pCurrent->m_pLeft = *pLastNode;
	if (*pLastNode != nullptr) {
		(*pLastNode)->m_pRight = pCurrent;
	}
	pCurrent = *pLastNode;

	if (pCurrent->m_pRight != nullptr) {
		Convert(pCurrent->m_pRight, pLastNode);
	}
}
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {

	BinaryTreeNode* pLastNodeInList = nullptr;
	Convert(pRootOfTree, &pLastNodeInList);

	BinaryTreeNode* pHead = pLastNodeInList;
	while (pHead->m_pLeft != nullptr && pHead != nullptr) {
		pHead = pHead->m_pLeft;
	}

	return pHead;
}