
//  remove duplicats from sorted list II 
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
        ListNode* ret = NULL;
        ListNode* prefix = NULL;
        ListNode* last_node = head;
        head = head->next;
        bool f = false;
        while (head != NULL) {
            if (last_node->val == head->val) {
                f = true;
                last_node == head;
                head = head->next;
            } else {
                if (!f) {
                    if (prefix != NULL) {
                        prefix->next = last_node;
                    }
                    prefix = last_node;
                    if (ret == NULL) {
                        ret = prefix;
                    }
                }
                last_node = head;
                head = head->next;
                f = false;
            }
        }
        if (f) {
            if (prefix != NULL) {
                prefix->next = NULL;
            } else {
                prefix = NULL; 
            }
        } else {
            if (prefix != NULL) {
                prefix->next = last_node;
            } else {
                prefix = last_node; 
            }
        }
        if (ret == NULL) {
            ret = prefix;
        }
        return ret;
    }
};

int main() {

    return 0;
}
