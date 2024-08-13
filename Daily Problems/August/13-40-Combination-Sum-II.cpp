class Solution {
public:
    void dfs(vector<int>& cand, int cur, int target, vector<int>& path, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(target < 0) return;
        
        int n = cand.size();

        for(int i = cur; i < n; i++){
            if(i > cur && cand[i] == cand[i-1]) continue;
            path.push_back(cand[i]);
            dfs(cand, i+1, target-cand[i], path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int>> res;
       vector<int> path;
       dfs(candidates, 0, target, path, res);
       return res;
    }
};

// This code is made with the help of suyalneeraj09 solution