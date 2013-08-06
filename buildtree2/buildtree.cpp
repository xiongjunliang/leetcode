
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty()) {
            return NULL;
        }
        return buildtree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildtree(vector<int>& inorder, int ileft, int iright,
            vector<int>& postorder, int pleft, int pright) {
        if (iright < ileft) {
            return NULL;
        }
        else {
            TreeNode* node = new TreeNode(postorder[pright]);
            int i = ileft;
            for (; i <= iright; ++i) {
                if (inorder[i] == postorder[pright]) {
                    break;
                }
            }
            int j = pleft - ileft + i;
            node->left = buildtree(inorder, ileft, i-1, postorder, pleft, j-1);
            node->right = buildtree(inorder, i+1, iright, postorder, j, pright-1);
        }
    }
};

int main() {

    return 0;
}
