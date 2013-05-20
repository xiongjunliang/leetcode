
//  remove duplicats from sorted list 
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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        ListNode* ret = head;
        ListNode* last_node = head;
        head = head->next;
        while (head != NULL) {
            if (last_node->val == head->val) {
                head = head->next;
            } else {
                last_node->next = head;
                last_node = head;
                head = head->next;
            }
        }
        last_node->next = NULL;
        return ret;
    }
};

int main() {

    return 0;
}
