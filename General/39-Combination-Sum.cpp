class Solution {
public:
    int vecSum(const vector<int>& vec){
        int sum = 0;
        for(int n: vec){
            sum += n;
        }
        return sum;
    }
    void generate(vector<int>& candidates, int target, int index, vector<vector<int>>&res, vector<int>cur){
        if(vecSum(cur) == target){
            res.push_back(cur);
            return;
        }
        if(vecSum(cur) > target) return;
        if(index == candidates.size()){
            return;
        }

        cur.push_back(candidates[index]);
        generate(candidates, target, index, res, cur);
        cur.pop_back();
        generate(candidates, target, index + 1, res, cur);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        generate(candidates, target, 0, res, {});
        return res;
    }
};
