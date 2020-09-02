//
// Created by mby on 30/06/2020.
//
#include <iostream>
#include <cassert>
#include "bst.h"

using std::cout;
using std::cin;
using std::endl;

inline int ReadValue()
{
   int value;
   cin >> value;

   return value;
}

inline bool StillHasInput()
{
    return !cin.eof();
}

void InitNode(TreeNode* node, int val)
{
    node->m_data = val;
    node->m_left = NULL;
    node->m_right = NULL;
}

TreeNode* CreateNode(int value)
{
    TreeNode* node = new TreeNode;
    InitNode(node, value);

    return node;
}

void InsertNode(TreeNode** root, TreeNode* newNode)
{
    if (!*root)
    {
        *root = newNode;
    }
    else
    {
        if (newNode->m_data < (*root)->m_data)
        {
            InsertNode(&(*root)->m_left, newNode);
        }
        else if(newNode->m_data > (*root)->m_data)
        {
            InsertNode(&(*root)->m_right, newNode);
        }
        else
        {
            delete newNode;
        }
    }
}

void InsertNode(TreeNode** root, int val)
{
    InsertNode(root, CreateNode(val));
}

TreeNode* BuildBST()
{
    TreeNode *root = NULL;
    TreeNode *newNode = NULL;

    int value = ReadValue();

    while (StillHasInput())
    {
        newNode = CreateNode(value);
        InsertNode(&root, newNode);
        value = ReadValue();
    }

    cin.clear();
    return root;
}


void DestroyBST(TreeNode** root)
{
    if (*root)
    {
        DestroyBST(&(*root)->m_left);
        DestroyBST(&(*root)->m_right);
        delete *root;
    }
    *root = NULL;
}

inline TreeNode* minValueNode(TreeNode * node)
{
	TreeNode * current = node;
    while (current && current->m_left != NULL)
        current = current->m_left;
 
    return current;
}


TreeNode* RemoveNode(TreeNode* root, int value)//void, **
{
	if (!root)
		return root;
 
 
    if (value < root->m_data)
        root->m_left = RemoveNode(root->m_left, value);

  	else if (value > root->m_data)
        root->m_right = RemoveNode(root->m_right, value);

    else
    {
        if (root->m_left == NULL)
        {
            TreeNode *temp = root->m_right;
            free(root);
            return temp;
        }
        else if (root->m_right == NULL)
        {
    		TreeNode *temp = root->m_left;
    		free(root);
    		return temp;
        }
 
        TreeNode * temp = minValueNode(root->m_right);
        root->m_data = temp->m_data;
 
        root->m_right = RemoveNode(root->m_right, temp->m_data);
    }
    return root;
}

bool IsInBst(const TreeNode* root, int val)
{
	if (!root)
		return false;
	if (root->m_data==val)
		return true;
	else if (root->m_data<val)
	{
		return IsInBst(root->m_right, val);
	}
	else if (root->m_data>val)
	{
		return IsInBst(root->m_left, val);
	}

}

int getBstDepth(const TreeNode* root)
{
	if(!root)
		return 0;
	int left_depth=getBstDepth(root->m_left);
	int right_depth=getBstDepth(root->m_right);
	if(left_depth>right_depth)
		return left_depth+1;
	else
		return right_depth+1;
	
}

bool IsEqual(const TreeNode* a, const TreeNode* b)
{
    if (!a || !b)
        return a == b;

    if (a->m_data == b->m_data)
        return IsEqual(a->m_left, b->m_left) && IsEqual(a->m_right, b->m_right);

    else
        return false;
}


void PrintBst(const TreeNode* root, PrintFunc func)
{
    func(root);
    cout<<endl;
}

void PrintInOrder(const TreeNode* root)
{
    if(root)
    {
        PrintInOrder(root->m_left);
        cout << root->m_data << " ";
        PrintInOrder(root->m_right);
    }
}

void PrintPreOrder(const TreeNode* root)
{
    if(root)
    {
        cout << root->m_data << " ";
        PrintPreOrder(root->m_left);
        PrintPreOrder(root->m_right);
    }
}

void PrintPostOrder(const TreeNode* root)
{
    if(root)
    {
        PrintPostOrder(root->m_right);
        PrintPostOrder(root->m_left);
        cout << root->m_data << " ";
    }
}

