
//  Merge Sorted List
//  http://leetcode.com/onlinejudge#question_21
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* ret = NULL;
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;
        ListNode* pre = NULL;
        while (pl1 != NULL && pl2 != NULL) {
            ListNode* next = NULL;
            if (pl1->val < pl2->val) {
                next = pl1;
                pl1 = pl1->next;
            } else {
                next = pl2;
                pl2 = pl2->next;
            }
            if (ret == NULL) {
                ret = next;
                pre = next;
            } else {
                pre->next = next;
                pre = pre->next;
            }
        }
        if (pl1 != NULL) {
            pre->next = pl1;
        }
        if (pl2 != NULL) {
            pre->next = pl2;
        }
        return ret;
    }
};

int main() 
{
    return 0;
}

