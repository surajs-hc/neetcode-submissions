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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return head;   
        }

        ListNode dummy;
        ListNode* builder = &dummy;

        ListNode* headCpy = head;
        int kCopy = k;
        deque<ListNode*> stk;
        while (headCpy && kCopy > 0) {
            stk.push_back(headCpy);
            --kCopy;
            headCpy = headCpy->next;
        }
        if (kCopy > 0) {
            return head;
        }

        // reverse k nodes
        while(!stk.empty()) {
            builder->next = stk.back();
            stk.pop_back();
            builder = builder->next;
        }


        builder->next = reverseKGroup(headCpy, k);


        return dummy.next;
    }
};
