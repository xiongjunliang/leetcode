
//  Partition List
//  http://leetcode.com/onlinejudge#question_86
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* pb = NULL;
        ListNode* pbc = NULL;
        ListNode* ps = NULL;
        ListNode* psc = NULL;
        while (head != NULL) {
            if (head->val >= x) {
                if (pb == NULL) {
                    pb = head;
                }
                if (pbc == NULL) {
                    pbc = head;
                } else {
                    pbc->next = head;
                    pbc = pbc->next;
                }
            } else {
                if (ps == NULL) {
                    ps = head;
                }
                if (psc == NULL) {
                    psc = head;
                } else {
                    psc->next = head;
                    psc = psc->next;
                }
            }
            head = head->next;
        }
        if (ps != NULL) {
            psc->next = pb;
            if (pbc != NULL) {
                pbc->next = NULL;
            }
            return ps;
        } else {
            return pb;
        }
    }
};

int main() {
    return 0;
}
