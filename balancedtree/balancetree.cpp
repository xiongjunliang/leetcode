
//  add 2 number
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Definition for binary tree
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        int left = 0;
        int right = 0;
        if (isBalanced(root->left)) {
            if (root->left != NULL) {
                left = root->left->val;
            }
        } else {
            return false;
        }
        if (isBalanced(root->right)) {
            if (root->right != NULL) {
                right = root->right->val;
            }
        } else {
            return false;
        }
        root->val = max(left, right) + 1;
        if (abs(left - right) <= 1) {
            return true;
        } else {
            return false;
        } 
    }
};


int main() {
    Solution s;
    s.isBalanced(NULL);
    return 0;
}
