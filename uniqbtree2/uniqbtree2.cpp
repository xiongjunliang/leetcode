

//  Uniq Binary Tree II
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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*> ret;
        dfs(ret, 1, n);
        return ret;
    }
private:
    void dfs(vector<TreeNode*>& ret, int left, int right) {
        if (right < left) {
            ret.push_back(NULL);
        } else {
            for (int i = left; i <= right; ++i) {
                vector<TreeNode*> lefts;
                dfs(lefts, left, i - 1);
                vector<TreeNode*> rights;
                dfs(rights, i + 1, right);
                for (int k = 0; k < lefts.size(); ++k) {
                    for (int j = 0; j < rights.size(); ++j) {
                        TreeNode* node = new TreeNode(i);
                        node->left = lefts[k];
                        node->right = rights[j];
                        ret.push_back(node);
                    }
                }

            } 
        }
    }

};

int main()
{
    int n;
    Solution s;
}

