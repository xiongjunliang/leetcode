


//  Binary Tree Max Path Sum 
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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        final_max = INT_MIN;
        get_max(root);
        return final_max;
    };
private:
    int get_max(TreeNode* node) {
        if (node == NULL) {
            return 0;
        } else {
            int left = MIN;
            int right = MIN;
            if (node->left != NULL) {
                left = get_max(node->left);
            }
            if (node->right != NULL) {    
                right = get_max(node->right);
            }
            int tmp_max = node->val;
            
            tmp_max = max(max(node->val, node->val + left + right), 
                        max(node->val + left, node->val + right));
            if (tmp_max > final_max) {
                final_max = tmp_max;
            }

            return max(node->val, max(node->val + left, node->val + right));
        }

    }
    inline int max(int a, int b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }
    int final_max;
    const static int MIN = -99999;
};


class Helper {
    public:
        static TreeNode* init_tree() {
            TreeNode* root = new TreeNode(2);
            root->left = new TreeNode(-1);
            root->left->left = new TreeNode(11);
            root->left->left->left = new TreeNode(7);
            root->left->left->right = new TreeNode(2);
            root->right = new TreeNode(8);
            root->right->left = new TreeNode(13);
            root->right->right = new TreeNode(4);
            root->right->right->left = new TreeNode(1);

            root->right->right = new TreeNode(0);
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
    cout << s.maxPathSum(root) << endl;
    Helper::uninit_tree(root);
    return 0;
}
