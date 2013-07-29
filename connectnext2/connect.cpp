
//  Connect Next II
//  http://leetcode.com/onlinejudge#question_117
//  Author: Xiongjun Liang

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
        connect(root, NULL) ;
    }
    void outer_connect(TreeLinkNode* node, TreeLinkNode* f_next) {
        if (f_next == NULL) {
            node->next = NULL;
        } else if (f_next->left != NULL) {
            node->next = f_next->left;
        } else if (f_next->right != NULL){
            node->next = f_next->right;
        } else {
            outer_connect(node, f_next->next);
        }
    }
    void connect(TreeLinkNode* root, TreeLinkNode* next) {
        if (root == NULL) {
            return;
        }
        if (root->right != NULL) {
            outer_connect(root->right, next);
            connect(root->right, root->right->next);
        } 
        if (root->left != NULL && root->right != NULL) {
            root->left->next = root->right;
            connect(root->left, root->left->next);
        } else if (root->left != NULL && root->right == NULL) {
            outer_connect(root->left, next);
            connect(root->left, root->left->next);
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
