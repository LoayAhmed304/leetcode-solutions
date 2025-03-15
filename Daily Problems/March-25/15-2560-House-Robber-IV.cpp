class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        while(l < r){
            int mid = (l + r) / 2;
            int cur = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    cur++;
                    i++; // skip
                }
            }
            if(cur >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;

    }
};
