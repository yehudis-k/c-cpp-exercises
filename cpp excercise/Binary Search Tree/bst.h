#ifndef __BST_H__
#define __BST_H__

enum ETraverseMode
{
	eInOrder,
	ePreOrder,
	ePostOrder
};

struct TreeNode
{
	int 		m_data;
	TreeNode*	m_left;
	TreeNode*	m_right;
};

typedef void(*PrintFunc)(const TreeNode*);


TreeNode* 	BuildBST();
void		DestroyBST(TreeNode** root);
void 		InsertNode(TreeNode** root, TreeNode* newNode);
void 		InsertNode(TreeNode** root, int val);
void		PrintInOrder(const TreeNode* root);
void		PrintPreOrder(const TreeNode* root);
void		PrintPostOrder(const TreeNode* root);
void 		PrintBst(const TreeNode* root, PrintFunc func = PrintInOrder);
TreeNode*	RemoveNode(TreeNode* root, int value);//**
bool		IsInBst(const TreeNode* root, int value);
int		    getBstDepth(const TreeNode* root);
bool        IsEqual(const TreeNode* a, const TreeNode* b);

// TODO until 1.7.20:
// 1. Consider print API redundancy.
// 2. Allow to add a new element in a convenient manner (should the user know "TreeNode*)?
// 3. Allow to remove an already existing element.
// 4. Allow to check whether a certain value exists in your BST.
// 5. Allow to get the BST's depth.

#endif // __BST_H__
