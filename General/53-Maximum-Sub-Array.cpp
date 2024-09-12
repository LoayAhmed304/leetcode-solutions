class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        int curSum = 0;
        for(int i = 0; i < n; i++){
            curSum += nums[i];
            res = max(res, curSum);
            if(curSum < 0) curSum = 0;
        }
        return res;
    }
};
