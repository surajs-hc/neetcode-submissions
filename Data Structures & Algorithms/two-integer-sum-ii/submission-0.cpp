class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lPtr = 0;
        int rPtr = numbers.size() - 1;

        while (lPtr < rPtr) {
            int temp_sum = numbers[lPtr] + numbers[rPtr];
            if (temp_sum == target) {
                return vector<int>{lPtr + 1, rPtr + 1};
            }
            else if (temp_sum < target) {
                ++lPtr;
            }
            else {
                --rPtr;
            }
        }

        return vector<int>{-1, -1};
    }
};
