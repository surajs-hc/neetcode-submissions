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
    bool hasCycle(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        while (hare && tortoise) {
            if (!hare->next) {
                return false;
            }
            hare = hare->next->next;
            tortoise = tortoise->next;
            if (hare == tortoise) {
                return true;
            }
        }

        return false;
    }
};
