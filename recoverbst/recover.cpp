
//  Recover Binary Search Tree
//  Link http://leetcode.com/onlinejudge#question_99
//  Author: Xiongjun Liang

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* pre = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        inorder(root, pre, first, second);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    void inorder(TreeNode* node, TreeNode*& pre, TreeNode*& first, TreeNode*& second) {
        if (node == NULL) {
            return;
        } 
        if (node->left != NULL) {
            inorder(node->left, pre, first, second);
        }
        if (pre != NULL && pre->val > node->val) {
            if (first == NULL) {
                first = pre;
            }
            second = node;
        }
        pre = node;
        if (node->right != NULL) {
            inorder(node->right, pre, first, second);
        }
    }

};

int main() {
    TreeNode root(2);
    TreeNode right(1);
    root.right = &right;

    Solution s;
    s.recoverTree(&root);

    cout << root.val << endl;

    return 0;
}
