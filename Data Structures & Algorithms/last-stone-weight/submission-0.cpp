class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while (stones.size() >= 2) {
            int stone_one = stones[0];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int stone_two = stones[0];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            int difference = stone_one - stone_two;
            if (difference > 0) {
                stones.push_back(difference);
            }
            push_heap(stones.begin(), stones.end());
        }

        if (stones.size() == 1) {
            return stones[0];
        }
        return 0;
    }
};
