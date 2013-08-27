
//  Reverse Nodes in K group
//  http://leetcode.com/onlinejudge#question_25
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        int len = 0;
        ListNode* node = head;
        while (node != NULL) {
            node = node->next;
            len ++;
        }
        int round = len / k;
        return reversek(head, k, round);
    }
    ListNode* reversek(ListNode* head, int k, int round) {
        if (round == 0) {
            return head;
        }
        ListNode* node = head;
        ListNode* next = node->next;
        int kk = k - 1;
        while (kk--) {
            ListNode* tmp = next;
            next = next->next;
            tmp->next = node;
            node = tmp;
        }
        head->next = reversek(next, k, round - 1);
        return node;
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
    
    ListNode* node = &l1;
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    Solution s;
    int k;
    while (cin >> k) {
        ListNode* n = s.reverseKGroup(&l1, k);
        while (n != NULL) {
            cout << n->val << " ";
            n = n->next;
        }
        cout << endl;
    }
    return 0;
}

