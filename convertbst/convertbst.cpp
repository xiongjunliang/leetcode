
//  Convert LinkedList To BST
//  http://leetcode.com/onlinejudge#question_109
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//  Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// !!! ATTENTION
// This Solution modifies the input LinkedList
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        ListNode* node = midnode(head); 
        TreeNode* tnode = new TreeNode(node->val);
        if (node != head) {
            tnode->left = sortedListToBST(head);
        }
        if (node->next != NULL) {
            tnode->right = sortedListToBST(node->next);
        }
        return tnode;
    }
    ListNode* midnode(ListNode* head) {
        ListNode* pn = head;
        ListNode* pnn = head;
        if (head == NULL) {
            return NULL;
        }
        ListNode* pre = NULL;
        while (pnn->next != NULL && pnn->next->next != NULL) {
            pre = pn;
            pn = pn->next;
            pnn = pnn->next->next;
        }
        // !!! ATTENTION
        // This Solution modifies the input LinkedList
        if (pre != NULL) {
            pre->next = NULL;
        }
        return pn;
    }
};

int main() {
    ListNode head(3);
    ListNode mid(5);
    ListNode tail(8);
    head.next = &mid;
    mid.next = &tail;
    Solution s;
    TreeNode* tree = s.sortedListToBST(&head);
    cout << tree->val << " ";
    cout << tree->left->val << " ";
    cout << tree->right->val << " ";
    return 0;
}


