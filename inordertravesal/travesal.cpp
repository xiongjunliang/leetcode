


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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if (root != NULL) {
            travesal(root, result);
        }
        return result;
        
    }
    void travesal(TreeNode* node, vector<int>& result)
    {
        if (node->left != NULL) {
            travesal(node->left, result);
        }
        result.push_back(node->val);
        if (node->right != NULL) {
            travesal(node->right, result);
        }
    }
};


int main()
{
    return 0;
}
