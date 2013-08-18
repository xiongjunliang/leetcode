
//  Rotate List
//  http://leetcode.com/onlinejudge#question_61
//  Author: Xiongjun Liang

#include <iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
   int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        ListNode* tmp = head;
        int len = 0;
        while (tmp != NULL) {
            tmp = tmp->next;
            len ++;
        }
        if (k >= len) {
            k = k%len;
        }
        if (k == 0) {
            return head;
        }
        ListNode* node = head;
        ListNode* newhead = head;
        ListNode* pre = NULL;
        while (node != NULL && k > 0) {
            node = node->next;
            k = k - 1;
        }
        if (node == NULL) {
            return head;
        }
        while (node->next != NULL) {
            node = node->next;
            newhead = newhead->next;
        }
        node->next = head;
        node = newhead;
        newhead = newhead->next;
        node->next = NULL;
        return newhead;
    }
};

int main() {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    Solution s;
    ListNode* newhead = s.rotateRight(&l1, 2);
    
    while (newhead != NULL) {
        cout << newhead->val << " ";
        newhead = newhead->next;
    }




    return 0;
}
