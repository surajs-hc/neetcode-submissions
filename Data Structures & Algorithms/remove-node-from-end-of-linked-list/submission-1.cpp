/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* curr = &dummy;

        int sz = 0;
        while (curr->next) {
            ++sz;
            curr = curr->next;
        }

        curr = dummy.next;
        ListNode* prev = &dummy;
        while (sz > 0) {
            if (sz == n) {
                prev->next = curr->next;
            }
            --sz;
            prev = curr;
            curr = curr->next;
        }

        return dummy.next;
    }
};
