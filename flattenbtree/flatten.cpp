
//  Flatten Binary Tree To LinkedList 
//  Link:http://leetcode.com/onlinejudge#question_114
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return;
        }
        TreeNode* right = root->right;
        flatten(root->left);
        root->right = root->left;
        // !!! ATTENTION
        // do NOT Forget to SET left pointer NULL
        root->left = NULL;
        while (root->right != NULL) {
            root = root->right;
        }
        root->right = right;
        flatten(right);
    }
};

int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n10(111);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n10;
    n2.right = &n4;
    
    Solution s;
    s.flatten(&n1);
    TreeNode* node = &n1;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->right;
    }
    cout << endl;
    return 0;
}

