

#include <iostream>

#include "BinaryTree.h"

BinaryTree::TreeNode::TreeNode() : value(0), left(nullptr), right(nullptr) {};
BinaryTree::TreeNode::TreeNode(int value) : value(value), left(nullptr), right(nullptr) {};
BinaryTree::TreeNode* BinaryTree::TreeNode::GetLeftNode() const
{
    return left;
}
BinaryTree::TreeNode* BinaryTree::TreeNode::GetRightNode() const
{
    return right;
}
int BinaryTree::TreeNode::GetValue() const
{
    return value;
}
void BinaryTree::TreeNode::SetRightNode(TreeNode* node)
{
    right = node;
}
void BinaryTree::TreeNode::SetLeftNode(TreeNode* node)
{
    left = node;
}
BinaryTree::BinaryTree()
{
    root = new TreeNode();
}
BinaryTree::BinaryTree(int value)
{
    root = new TreeNode(value);
}
BinaryTree::~BinaryTree()
{
    destruct(root);
}
void BinaryTree::Insert(int value)
{
    if (root->GetValue() == 0)
    {
        delete root;
        root = new TreeNode(value);
        return;
    }
    TreeNode* node = root;
    insert(node, value);
}
BinaryTree::TreeNode* BinaryTree::Search(int val) const
{
    return search(root, val);
}
BinaryTree::TreeNode* BinaryTree::CreateMinimalBST(int* arrptr, int start, int end)
{
    if (end < start)
        return nullptr;
    if (end == start)
        return new TreeNode(arrptr[start]);
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(arrptr[mid]);
    if (root->GetValue() == 0)
        root = node;
    node->SetRightNode(CreateMinimalBST(arrptr, mid + 1, end));
    node->SetLeftNode(CreateMinimalBST(arrptr, start, mid - 1));
}

BinaryTree::TreeNode* BinaryTree::search(TreeNode* node, int val) const
{
    if (node == nullptr)
        return nullptr;
    if (node->GetValue() == val)
        return node;
    return search(val < node->GetValue() ? node->GetLeftNode() : node->GetRightNode(), val);
}
void BinaryTree::insert(TreeNode* currentNode, int val)
{
    bool nextIsLess = val < currentNode->GetValue();
    TreeNode* next = nextIsLess
        ? currentNode->GetLeftNode()
        : currentNode->GetRightNode();
    if (next == nullptr)
    {
        TreeNode* nextNode = new TreeNode(val);
        if (nextIsLess)
            currentNode->SetLeftNode(nextNode);
        else
            currentNode->SetRightNode(nextNode);
        return;
    }
    insert(next, val);
}
void BinaryTree::destruct(TreeNode* node)
{
    if (node != nullptr)
    {
        destruct(node->GetLeftNode());
        destruct(node->GetRightNode());
        delete node;
    }
}