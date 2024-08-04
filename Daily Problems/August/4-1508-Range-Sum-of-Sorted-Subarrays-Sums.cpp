class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector< int>res;
        const int Z = 1e9+7;
        
        for(int i =0; i<n; i++)
        {
            res.push_back(nums[i]);
            int s = nums[i];
            for(int j=i+1; j<n; j++){
                s += nums[j];
                res.push_back(s);
            }
        }

        sort(res.begin(), res.end());
        
        int sum = 0;
         for(int i =left; i<right+1; i++){
            sum = (sum + res[i-1]) % Z;
         }
        return sum;
    }
};