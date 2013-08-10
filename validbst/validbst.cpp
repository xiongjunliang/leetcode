
//  Valid BST
//  http://leetcode.com/onlinejudge#question_98
//  Author: Xiongjun Liang

#include <iostream>

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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pre = INT_MIN;
        return isvalid(root, &pre);
    }
    bool isvalid(TreeNode* node, int* pre) {
        if (node == NULL) {
            return true;
        }
        if (node->left != NULL && 
                !(isvalid(node->left, pre))) {
            return false;
        }
        if (node->val <= *pre) {
            return false;
        }
        *pre = node->val;
        return isvalid(node->right, pre);
    }
};

int main() {
    return 0;
}
