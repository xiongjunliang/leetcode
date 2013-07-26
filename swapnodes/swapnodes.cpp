/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* p = head;
        ListNode* ppre = NULL;
        ListNode* pprepre = NULL;
        while (p != NULL && p->next != NULL) {
            ppre = p;
            p = p->next;
            ListNode* pNext = p->next;
            if (ppre == head) {
                head = p;
            }
            if (pprepre != NULL) {
                pprepre->next = p;
            }
            p->next = ppre;
            ppre->next = pNext;
            pprepre = ppre;
            p = pNext;
        }
        return head;
    }
};
