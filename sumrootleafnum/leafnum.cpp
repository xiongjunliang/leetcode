//
//  Sum Root To Leaf Num
//  Xiongjun Liang

#include <iostream>
#include <string>
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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        //  DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }
        sum = 0;
        travesal(root, 0);
        return sum;
    }
private:
    void travesal(TreeNode *node, int base) {
        int value = (base * 10) + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += value;
            return;
        } 
        if (node->left != NULL) {
            travesal(node->left, value);
        }
        if (node->right != NULL) {
            travesal(node->right, value);
        } 
    }
private:
    int sum;
};


class Helper {
public:
    static TreeNode* init_tree() {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        return root;
    }
    static void uninit_tree(TreeNode* root) {
        if (root->left != NULL) {
            uninit_tree(root->left);
        }
        if (root->right != NULL) {
            uninit_tree(root->right);
        }
        delete root;
    }
};

int main() 
{
    Solution s;
    TreeNode* root = Helper::init_tree();
    int result = s.sumNumbers(root);
    cout << result << endl;
    Helper::uninit_tree(root);
    return 0;
}

