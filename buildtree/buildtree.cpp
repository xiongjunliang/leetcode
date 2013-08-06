
//  Construct Binary Tree using Inorder & Postorder Travesal
//  Link http://leetcode.com/onlinejudge#question_106
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty()) {
            return NULL;
        }
        return buildtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildtree(vector<int>& preorder, int ileft, int iright,
            vector<int>& inorder, int pleft, int pright) {
        if (iright < ileft) {
            return NULL;
        }
        else {
            TreeNode* node = new TreeNode(preorder[ileft]);
            int i = pleft;
            for (; i <= pright; ++i) {
                if (inorder[i] == preorder[ileft]) {
                    break;
                }
            }
            int j = ileft - pleft + i;
            node->left = buildtree(preorder, ileft+1, j, inorder, pleft, i-1);
            node->right = buildtree(preorder, j+1, iright, inorder, i+1, pright);
        }
    }
};

int main() {

    return 0;
}
