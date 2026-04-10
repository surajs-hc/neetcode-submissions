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
private:
    ListNode* divide(const vector<ListNode*>& lists, int low, int high) {
        if (high <= low) {
            return nullptr;
        }
        if (high - low == 1) {
            return lists[low];
        }

        int mid = (low + high) / 2;
        ListNode* left = divide(lists, low, mid);
        ListNode* right = divide(lists, mid, high);

        return merge(left, right);
    }

    ListNode* merge(ListNode* one, ListNode* two) {
        ListNode dummy;
        ListNode* builder = &dummy;

        while (one && two) {
            if (one->val < two->val) {
                builder->next = one;
                one = one->next;
            }
            else {
                builder->next = two;
                two = two->next;
            }
            builder = builder->next;
        }
        if (one) {
            builder->next = one;
        }
        if (two) {
            builder->next = two;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide(lists, 0, lists.size());
    }
};
