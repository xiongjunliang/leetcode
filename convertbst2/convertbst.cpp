
//  Convert LinkedList To BST
//  http://leetcode.com/onlinejudge#question_108
//  Author: Xiongjun Liang

#include <iostream>
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty()) {
            return NULL;
        } 
        return convert(num, 0, num.size() - 1);
    }
private:
    TreeNode* convert(vector<int>& num, int left, int right) {
        if (right < left) {
            return NULL;
        } 
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = convert(num, left, mid - 1);
        node->right = convert(num, mid + 1, right);
        return node;
    }
};

int main() {
    return 0;
}


