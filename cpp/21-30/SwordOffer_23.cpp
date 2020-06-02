struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


ListNode* MeetingNode(ListNode* pHead) {

	if (pHead == nullptr) {
		return nullptr;
	}

	ListNode* pSlow = pHead;
	ListNode* pFast = pHead;

	while (pSlow != pFast) {
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext->m_pNext;
	}

	return pSlow;
}
ListNode* EntryNode(ListNode* pHead) {

	if (pHead == nullptr) {
		return nullptr;
	}

	ListNode* meetingNode = MeetingNode(pHead);

	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_pNext != meetingNode) {
		nodesInLoop++;
		pNode1 = pNode1->m_pNext;
	}

	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; i++) {
		pNode1 = pNode1->m_pNext;
	}

	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2) {
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode1;

}