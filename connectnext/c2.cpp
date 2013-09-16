///////////////////////////////////////////////////////////
//                                                       //
//  Copyright (c) Liang Xiongjun All Rights Reserved     //
//                                                       //
///////////////////////////////////////////////////////////
 
 
// Author Xiongjun Liang(xiongjunliang@gmail.com)
// Date 2013/09/16 15:52:00
// Connect Next I
// http://leetcode.com/onlinejudge#question_116


#include <iostream>
#include <string>
#include <vector>

using namespace std;


//  Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return;
        }
        TreeLinkNode* next = root->next;
        if (root->right != NULL) {
            if (next != NULL) {
                root->right->next = next->left;
            }
            connect(root->right);
        }
        if (root->left != NULL) {
            root->left->next = root->right;
            connect(root->left);
        }
    }
};



int main() {
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
