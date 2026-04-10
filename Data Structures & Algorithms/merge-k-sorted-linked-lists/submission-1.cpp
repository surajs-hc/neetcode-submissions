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

        // head node value, index in lists
        vector<pair<int, int>> heap;
        for (int i = 0, k = lists.size(); i < k; ++i) {
            if (lists[i])
                heap.push_back({lists[i]->val, i});
        }
        make_heap(heap.begin(), heap.end(), greater<pair<int, int>>());

        while (!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
            const auto [nodeValue, index] = heap.back();
            heap.pop_back();
            buildPtr->next = lists[index];
            buildPtr = buildPtr->next;
            lists[index] = lists[index]->next;

            if (lists[index]) {
                heap.push_back({lists[index]->val, index});
                push_heap(heap.begin(), heap.end(), greater<pair<int, int>>());
            }
        }

        return dummy.next;
    }
};
