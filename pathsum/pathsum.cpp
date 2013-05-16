
//  Binary Tree Max Path Sum 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        }  
        if (root->left != NULL) {
            if (hasPathSum(root->left, sum - root->val)) {
                return true;
            }
        }
        if (root->right != NULL) {
            if (hasPathSum(root->right, sum - root->val)) {
                return true;
            }
        }
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
