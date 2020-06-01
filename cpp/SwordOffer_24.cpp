struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


ListNode* ReverseList(ListNode* pHead) {
	
	if (pHead == nullptr || pHead->m_pNext == nullptr) {
		return pHead;
	}

	ListNode* p1 = pHead;
	ListNode* p2 = p1->m_pNext;
	ListNode* p3 = nullptr;

	while (p2!=nullptr) {
		p3 = p2->m_pNext;
		p2->m_pNext = p1;
		p1 = p2;
		p2 = p3;

	}

	pHead->m_pNext = nullptr;
	pHead = p1;
	return pHead;
}