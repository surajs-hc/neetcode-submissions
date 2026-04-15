class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        nums.insert(n);
        while (n != 1) {
            int s = 0;
            while (n > 0) {
                s += pow((n % 10), 2);
                n /= 10;
            }
            n = s;
            if (nums.contains(n)) {
                return false;
            }
            nums.insert(n);
        }
        return true;
    }
};
