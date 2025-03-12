class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pCount = 0, nCount = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int num = nums[i];
            if(num > 0) pCount++;
            else if(num < 0) nCount++;
        }
        return max(nCount, pCount);
    }
};
