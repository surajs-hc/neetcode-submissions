class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(nums);
        make_heap(heap.begin(), heap.end());

        int kth_largest = 0;
        for (int i = 0; i < k; ++i) {
            kth_largest = heap[0];
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }

        return kth_largest;
    }
};
