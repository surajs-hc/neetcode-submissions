class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solutions;
        sort(nums.begin(), nums.end());
        
        // [0, 0, 0, 0]
        /*
        lPtr = 1
        mPtr = 2 -> 2 -> 3
        rPtr = 3

        */

        for (int lPtr = 0, n = nums.size(); lPtr < n; ++lPtr) {
            if (lPtr > 0 && nums[lPtr] == nums[lPtr - 1]) {
                continue;
            }
            int mPtr = lPtr + 1;
            int rPtr = n - 1;

            while (mPtr < rPtr) {
                int target = nums[lPtr] + nums[mPtr] + nums[rPtr];
                if (target == 0) {
                    solutions.push_back(vector<int>{nums[lPtr], nums[mPtr], nums[rPtr]});
                    do {
                        ++mPtr;
                    } while (mPtr < rPtr && nums[mPtr] == nums[mPtr - 1]);
                }
                else if (target < 0) {
                    ++mPtr;
                }
                else {
                    --rPtr;
                }
            }
        }

        return solutions;
    }
};

// -4 -1 -1 0 1 2
// 