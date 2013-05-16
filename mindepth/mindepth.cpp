
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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        } else if (root->left != NULL && root->right != NULL) {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return min(left, right) + 1;
        } else if (root->left != NULL && root->right == NULL) {
            return minDepth(root->left) + 1;
        } else {
            return minDepth(root->right) + 1;
        }

    }
};

int main() {
    return 0;
}
