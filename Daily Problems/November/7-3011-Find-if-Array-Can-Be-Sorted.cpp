class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] <= nums[j + 1]) {
                    continue;
                } else {
                    if (__builtin_popcount(nums[j]) ==
                        __builtin_popcount(nums[j + 1])) {
                        swap(nums[j], nums[j + 1]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
