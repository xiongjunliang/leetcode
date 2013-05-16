
//  Path Sum II 
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
   vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<vector<int> > result;
       vector<int> path;
       if (root == NULL) {
            return result;
       }
       pathSum(root, sum, path, result, 0);
       return result;
    }
private:
    void pathSum(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& result, int index) {
        if (path.size() > index) {
            path[index] = node->val;
        } else {
            path.push_back(node->val);
        }
        if (node->left != NULL) {
            pathSum(node->left, sum - node->val, path, result, index + 1);
        } 
        if (node->right != NULL) {
            pathSum(node->right, sum - node->val, path, result, index + 1);
        }
        if (node->left == NULL && node->right == NULL && sum == node->val) {
            vector<int> p;
            for (int i = 0; i <= index; ++i) {
                p.push_back(path[i]);
            }
            result.push_back(p);
        }
    }
};

int main() {
    return 0;
}
