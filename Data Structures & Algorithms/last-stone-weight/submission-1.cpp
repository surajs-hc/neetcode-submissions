class Solution {
public:
    // O(nlogn) time, O(n) space (input array only), O(1) additional space
    int lastStoneWeight(vector<int>& stones) {
        // n
        make_heap(stones.begin(), stones.end());
        // n
        while (stones.size() >= 2) {
            int stone_one = stones[0];
            // logn
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int stone_two = stones[0];
            // logn
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int difference = stone_one - stone_two;
            if (difference > 0) {
                stones.push_back(difference);
            }
            // logn
            push_heap(stones.begin(), stones.end());
        }

        if (stones.size() == 1) {
            return stones[0];
        }
        return 0;
    }
};
