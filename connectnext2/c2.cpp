///////////////////////////////////////////////////////////
//                                                       //
//  Copyright (c) Liang Xiongjun All Rights Reserved     //
//                                                       //
///////////////////////////////////////////////////////////
 
 
//  Author Xiongjun Liang(xiongjunliang@gmail.com)
//  Date 2013/09/16 15:20:46
//  Connect Next II
//  http://leetcode.com/onlinejudge#question_117

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
        TreeLinkNode* onext = NULL;
        while (next != NULL) {
            if (next->left != NULL) {
                onext = next->left;
                break;
            }
            if (next->right != NULL)
            {
                onext = next->right;
                break;
            }
            next = next->next;
        }
        if (root->right != NULL) {
            root->right->next = onext;
            connect(root->right);
        }
        if (root->left != NULL) {
            if (root->right != NULL) {
                root->left->next = root->right;
            }
            else {
                root->left->next = onext;
            }
            connect(root->left);
        }
    }
};


int main() {
    TreeLinkNode root(3);
    TreeLinkNode left(9);
    TreeLinkNode right(20);
    TreeLinkNode rleft(15);
    TreeLinkNode rright(7);
    root.left = &left;
    root.right = &right;
    right.left = &rleft;
    right.right = &rright;

    Solution s;
    s.connect(&root);

    cout << rleft.val << " rleft next " << (rleft.next)->val << endl;

    return 0;
}






/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
