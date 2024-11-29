class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 2) return *max_element(nums.begin(), nums.end());
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i<nums.size(); i++){
            nums[i] = max(nums[i - 1], nums[i] + nums[i-2]);
        }
        return max(nums[n-1], nums[n-2]);
    }
    int rob(vector<int>& nums) {
        if(nums.size() <= 2) return *max_element(nums.begin(), nums.end());
        vector<int>nums1;
        vector<int>nums2;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) nums1.push_back(nums[i]);
            if(i!= nums.size()-1)nums2.push_back(nums[i]);
        }
        return max(rob1(nums1), rob1(nums2));
    }
};
