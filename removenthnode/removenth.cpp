
//  Remove Nth Node from end 
//  http://leetcode.com/onlinejudge#question_19
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* node = head;
        int len = 0;
        while (node != NULL) {
            node = node->next;
            len ++;
        }
        if (n == len) {
            node = head->next;
            return node;
        }
        node = head;
        while (n --) {
            node = node->next;
        }
        ListNode* pre = head;
        while (node->next != NULL) {
            pre = pre->next;
            node = node->next;
        }
        node = pre->next;
        pre->next = node->next;
        return head;
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
    int n;
    ListNode* node = &l1;
    while (cin >> n) {
        node = s.removeNthFromEnd(node, n);
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
    return 0;
}

