#pragma once

#include <vector>
#include <math.h>

class BinaryTree
{
public:
    class TreeNode
    {
    private:
        TreeNode* left;
        TreeNode* right;
        const int value;
    public:
        TreeNode();
        TreeNode(int value);
        TreeNode* GetLeftNode() const;
        TreeNode* GetRightNode() const;
        int GetValue() const;
        void SetRightNode(TreeNode* node);
        void SetLeftNode(TreeNode* node);
    };
    BinaryTree();
    BinaryTree(int value);
    ~BinaryTree();
    void Insert(int value);
    TreeNode* Search(int value) const;
    void CreateMinimalBST(int* arrptr, int begin, int end);
private:
    TreeNode* root;
    TreeNode* search(TreeNode* node, int val) const;
    void insert(TreeNode* node, int val);
    void destruct(TreeNode* node);
};
