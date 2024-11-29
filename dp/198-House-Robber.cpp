class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 2) return *max_element(nums.begin(), nums.end());
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i<nums.size(); i++){
            nums[i] = max(nums[i - 1], nums[i] + nums[i-2]);
        }
        return max(nums[n-1], nums[n-2]);
    }
};
