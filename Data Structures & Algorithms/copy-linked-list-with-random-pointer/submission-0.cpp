/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        unordered_map<Node*, Node*> mp;

        Node* temp = head;
        Node* dummyTemp = &dummy;
        while (temp) {
            dummyTemp->next = new Node(temp->val);
            dummyTemp->next->random = temp->random; // temporarily store old random, for mapping
            mp[temp] = dummyTemp->next;

            temp = temp->next;
            dummyTemp = dummyTemp->next;            
        }

        // we have copied the array, up until the randoms
        dummyTemp = dummy.next;
        while (dummyTemp) {
            dummyTemp->random = mp[dummyTemp->random];
            dummyTemp = dummyTemp->next;
        }

        return dummy.next;
    }
};
