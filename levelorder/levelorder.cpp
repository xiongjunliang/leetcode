
//  Level Order Travesal 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        if (root == NULL) {
            return result;
        }
        deque<TreeNode*> queue;
        queue.push_back(root);
        int current_idx = 0;
        int level_idx = 0;
        int max_idx = 0;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop_front();
            level.push_back(node->val);
            if (node->left != NULL) {
                queue.push_back(node->left);
                max_idx ++;
            } 
            if (node->right != NULL) {
                queue.push_back(node->right);
                max_idx++;
            }
            if (current_idx == level_idx) {
                result.push_back(level);
                level.clear();
                level_idx = max_idx;
            }
            current_idx ++;
        }
        return result;
    }
};

int main() {
    return 0;
}
