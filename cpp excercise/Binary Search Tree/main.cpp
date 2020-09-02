#include <iostream>
#include <cassert>
#include "bst.h"

void ValidateDestruction(TreeNode* root)
{
    assert(!root);
}

int main() {
    TreeNode* root = BuildBST();
    PrintBst(root, PrintPreOrder);
    PrintBst(root, PrintPostOrder);
    PrintBst(root, PrintInOrder);
    /*InsertNode(&root, 20);
    PrintBst(root, PrintPreOrder);
    PrintBst(root, PrintPreOrder);
    PrintBst(root, PrintPostOrder);
    InsertNode(&root, 20);
    PrintBst(root);
	RemoveNode(root, 15);
	PrintBst(root);
	std::cout<<"does 5 exist? "<<IsInBst(root,5)<<std::endl;
	std::cout<<"does 100 exist? "<<IsInBst(root,100)<<std::endl;
	std::cout<<"depth: "<<getBstDepth(root)<<std::endl;*/
    DestroyBST(&root);
    root = NULL;

    ValidateDestruction(root);
    return 0;
}
