
//  Merge K Sorted List
//  http://leetcode.com/onlinejudge#question_23
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator() (ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* ret = NULL;
        ListNode* current = NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                q.push(lists[i]);
            }
        }
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            if (ret == NULL) {
                ret = node;
                current = node;
            } else {
                current->next = node;
                current = node;
            }
            if (node->next != NULL) {
                q.push(node->next);
            }
        }
        return ret;
    }
};

int main() {
    vector<ListNode*> v;
    Solution s;
    s.mergeKLists(v);
    return 0;
}

