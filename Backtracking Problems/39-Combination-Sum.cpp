class Solution {
public:
    void dfs(vector<int>& subset, vector<int>& nums, int i, vector<vector<int>>& res, int target){
        if(target == 0){
            res.push_back(subset);
            return;
        }
        if(target < 0 || i >= nums.size()) return;

        subset.push_back(nums[i]);
        dfs(subset, nums, i, res, target - nums[i]);
        subset.pop_back();
        dfs(subset, nums, i+1, res, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subset;
        vector<vector<int>> res;

        dfs(subset, nums, 0, res, target);
        return res;
    }
};
