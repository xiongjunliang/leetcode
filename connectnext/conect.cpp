
//  Palindrome Partition I
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
    void connect(TreeLinkNode* root, TreeLinkNode* next) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            root->left->next = root->right;
            connect(root->left, root->left->next);
        }
        if (root->right != NULL && next != NULL) {
            root->right->next = next->left;
            connect(root->right, next->left);
        } else {
            connect(root->right, NULL);
        }
    }
};

int main() {
    return 0;
}
