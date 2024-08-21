class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& res, vector<int>& sol){
        if(sol.size() == nums.size()){
            res.push_back(sol);
        }

        for(const auto& num: nums){
            auto it = find(sol.begin(), sol.end(), num);
            if(it == sol.end()){
                sol.push_back(num);
                backtrack(nums, res, sol);
                sol.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sol;
        vector<vector<int>>res;
        backtrack(nums, res, sol);
        return res;
    }
};
