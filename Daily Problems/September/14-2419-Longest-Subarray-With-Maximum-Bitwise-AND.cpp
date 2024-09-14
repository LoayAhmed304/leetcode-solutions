class Solution {
public:
    // ANDing will always be decreasing as long as the numbers are different
    // So the question here is to get the longest subarray of the largest value present

    int longestSubarray(vector<int>& nums) {
        // Index of first occurence of the largest value
        int maxElIndex = max_element(nums.begin(), nums.end()) - nums.begin(); // Index
        int maxEl = nums[maxElIndex]; // Largest value

        int n = nums.size();
        int res = 0;
        int temp = 0;

        for(int i = maxElIndex; i < n; ++i){
            if(nums[i] == maxEl){
                ++temp;
                res = max(res, temp);
            }else{ // Sequence broken
                temp = 0;
            }
        }

        return res;
    }
};
