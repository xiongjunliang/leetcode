
//  ZigZag Level Order Travesal 
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
                int sz = level.size();
                if (result.size()%2 == 1) {
                    for (int i = 0; i < sz/2; ++i) {
                        int tmp = level[i];
                        level[i] = level[sz-i-1];
                        level[sz-i-1] = tmp;
                    }
                }
                
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
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    
    root.left = &left;
    root.right = &right;
    
    Solution s;
    vector<vector<int> > r = s.zigzagLevelOrder(&root);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
