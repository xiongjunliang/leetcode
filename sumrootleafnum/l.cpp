
//
//  Sum Root To Leaf Num
//  http://leetcode.com/onlinejudge#question_129
//  Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  Definition for binary tree
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
        // DO NOT write int main() function
        sum = 0;
        if (root == NULL) {
            return sum;
        }
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* node, int current) {
        current = current*10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += current; 
        } else {
            if (node->left != NULL) {
                dfs(node->left, current);
            }
            if (node->right != NULL) {
                dfs(node->right, current);
            }
        }
    }
private:
    int sum;
};

int main() {
    return 0;
}

