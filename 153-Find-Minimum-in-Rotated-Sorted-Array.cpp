class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int l=0, r=nums.size()-1;

        while(l <= r)
        {
            if(nums[l] < nums[r]){
                res = min(res, nums[l]);
                break;
            }

            int mid = (l+r)/2;
            res = min(nums[mid], res);
            if(nums[mid] >= nums[l]){
                l = mid+1;
            }
            else
                r = mid - 1;
        }
        return res;
    }
};
