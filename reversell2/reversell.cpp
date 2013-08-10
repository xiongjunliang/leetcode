
//  Reverse LinkedList II
//  http://leetcode.com/onlinejudge#question_92
//  Author: Xiongjun Liang

//  NOT a diffcult problem, 
//  but it is really difficult to write bug free code

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        int sub = n - m;
        ListNode* lhead = head;
        ListNode* pre_start = NULL;
        ListNode* node = NULL;
        ListNode* start = NULL;
        while (m > 1) {
            m --;
            if (pre_start == NULL) {
                pre_start = head;
            } else {
                pre_start = pre_start->next;
            }
        }
        if (pre_start == NULL) {
            node = head;
        } else {
            node = pre_start->next;
        }
        start = node;
        ListNode* pre = node;
        node = node->next;
        ListNode* next = NULL;
        if (node != NULL) {
            next = node->next;
        }
        while (sub > 0) {
            sub --;
            node->next = pre;
            pre = node;
            node = next;
            if (next != NULL) {
                next = next->next;
            }
        }
        start->next = node;
        if (pre_start == NULL) {
            return pre;
        } else {
            pre_start->next = pre;
            return lhead;
        }
    }
};

void out_put(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

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
    ListNode* r = s.reverseBetween(&l1, 2, 4);
    out_put(r);

    return 0;
}

