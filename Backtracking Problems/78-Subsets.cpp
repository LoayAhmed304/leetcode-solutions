class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>&subset, vector<vector<int>>&res){
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1, nums, subset, res);
        subset.pop_back();
        dfs(i+1, nums, subset, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>subset;
        vector<vector<int>> res;
        dfs(0, nums, subset, res);
        return res;
    }
};
