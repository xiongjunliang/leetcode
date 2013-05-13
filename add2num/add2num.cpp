
//  add 2 number
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        int mov = 0;
        while (l1 != NULL && l2 != NULL) {
            head->next = new ListNode(0);
            head = head->next;
            head->val = l1->val + l2->val + mov;
            mov = 0;
            if (head->val >= 10) {
                head->val -= 10;
                mov = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            head->next = new ListNode(0);
            head = head->next;
            head->val = l1->val + mov;
            mov = 0;
            if (head->val >= 10) {
                head->val -= 10;
                mov = 1;
            }
            l1 = l1->next;
        }
        while (l2 != NULL) {
            head->next = new ListNode(0);
            head = head->next;
            head->val = l2->val + mov;
            mov = 0;
            if (head->val >= 10) {
                head->val -= 10;
                mov = 1;
            }
            l2 = l2->next;
        }
        if (mov == 1) {
            head->next = new ListNode(1);
        }
        head = ret;
        ret = ret->next;
        delete head;
        return ret;
    }   
};

int main() {

    int x, y;
    Solution s;
    while (cin >> x >> y) {
        ListNode l1(x), l2(y);
        ListNode* ret = s.addTwoNumbers(&l1, &l2);
        while (ret != NULL) {
            cout << ret->val;
            ret = ret->next;
        }
    }

    return 0;
}





