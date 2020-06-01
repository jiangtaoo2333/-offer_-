struct BinaryTreeNode
{
	BinaryTreeNode* m_pParent;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {

	if (pNode == nullptr) {
		return nullptr;
	}

	BinaryTreeNode* pNext = nullptr;

	if (pNode->m_pRight != nullptr) {
		BinaryTreeNode* pRight = pNode->m_pRight;
		if (pRight->m_pLeft != nullptr) {
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}

	else if(pNode->m_pRight == nullptr){

		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;

		while (pParent != nullptr && pParent->m_pRight == pCurrent) {
			pNode = pParent;
			pParent = pNode->m_pParent;
		}

		pNext = pParent;
	}
}