class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) {
            double time_to_completion = 1.0 * (target - position[i]) / speed[i];
            cars.emplace_back(position[i], time_to_completion);
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 1;
        for (int i = 1; i < n; ++i) {
            if (cars[i].second > cars[i - 1].second) {
                ++fleets;
            }
            else {
                cars[i].second = cars[i - 1].second;
            }
        }

        return fleets;
    }
};
