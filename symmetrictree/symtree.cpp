

//  SymmetricTree 
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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        return issym(root->left, root->right); 
    }
private:
    bool issym(TreeNode* left, TreeNode* right) {
        if (left == NULL  && right == NULL) {
            return true;
        } else if (left != NULL && right != NULL) {
            return left->val == right->val &&
                   issym(left->left, right->right) &&
                   issym(left->right, right->left);
        }
        return false;
    }
};

int main()
{
    return 0;
}


