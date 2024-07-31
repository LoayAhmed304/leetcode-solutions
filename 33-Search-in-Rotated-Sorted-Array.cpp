class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = nums[0];
        int l=0, r=nums.size()-1;

        while(l <= r)
        {
            int mid = (l+r)/2;

            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[l]){    // left sorted
                if(target > nums[mid] || target < nums[l]) 
                    l = mid+1;
                else
                    r=  mid-1;
            }
            else{   // right sorted ( nums[mid]  < nums[l] )
                if(target < nums[mid] || target > nums[r])
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};
