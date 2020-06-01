struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};
unsigned int  GetListLength(ListNode* pHead) {

	unsigned int length = 0;
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		length++;
		pNode = pNode->m_pNext;
	}
	return length;
}

ListNode* FindFistCommonNode(ListNode* pHead1, ListNode* pHead2) {

	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);

	ListNode* pHeadLong;
	ListNode* pHeadShort;
	if (length1 > length2) {
		pHeadLong = pHead1;
		pHeadShort = pHead2;
	}

	else {
		pHeadLong = pHead2;
		pHeadShort = pHead1;
	}

	unsigned int diff = length1 - length2;
	for (int i = 0; i < diff; i++) {
		pHeadLong = pHeadLong->m_pNext;
	}

	while ((pHeadLong != nullptr) && (pHeadShort != nullptr) && (pHeadShort != pHeadShort)) {
		pHeadLong = pHeadLong->m_pNext;
		pHeadShort = pHeadShort->m_pNext;
	}

	return pHeadLong;

}