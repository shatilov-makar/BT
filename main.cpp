
#include <iostream>

#include "BinaryTree.h"


int main()
{
    constexpr int arrSize = 7;
    int arr[arrSize] = { 10, 20,30,40,50,60,70 };
    int* arrptr = &arr[0];
    BinaryTree* tree = new BinaryTree();
    tree->CreateMinimalBST(arrptr, 0, arrSize - 1);
    BinaryTree::TreeNode* searchNode = tree->Search(10);
    delete tree;
}