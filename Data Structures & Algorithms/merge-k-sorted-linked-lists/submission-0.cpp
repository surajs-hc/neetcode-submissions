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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* buildPtr = &dummy;

        int minIndex = -1;
        do {
            minIndex = -1;
            int minVal = 1001;
            for (int i = 0, k = lists.size(); i < k; ++i) {
                if (lists[i] && (lists[i]->val < minVal)) {
                    minIndex = i;
                    minVal = lists[i]->val;
                }
            }

            if (minIndex != -1) {
                buildPtr->next = lists[minIndex];
                lists[minIndex] = lists[minIndex]->next;
                buildPtr = buildPtr->next;
            }
        } while (minIndex != -1);
        buildPtr->next = nullptr;
        return dummy.next;
    }
};
