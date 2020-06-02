#include<exception>
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == nullptr || inorder == nullptr || length == 0) {
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {

	int rootValue = startInorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder) {
		if (startInorder == endInorder) {
			return root;
		}
		else {
			throw std::exception("invalid input");
		}
	}

	int* rootInorder = startInorder;
	while (rootInorder < endInorder && *rootInorder != rootValue) {
		rootInorder++;
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorder = startPreorder + leftLength;

	if (leftLength > 0) {
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorder, startInorder, rootInorder - 1);
	}

	if (endPreorder - leftPreorder > 0) {
		root->m_pRight = ConstructCore(leftPreorder + 1, endPreorder, rootInorder + 1, endInorder);
	}
}