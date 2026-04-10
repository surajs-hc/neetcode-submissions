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
        helper(&dummy, head, n);
        return dummy.next;
    }

    ListNode* helper(ListNode* prev, ListNode* head, int& n) {
        if (head->next) {
            helper(head, head->next, n);
        }
        --n;
        if (n == 0) {
            prev->next = head->next;
        }

        return head;
    }
};
