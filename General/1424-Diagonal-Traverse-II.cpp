class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>mp;
        vector<int> res;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j =0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        int curr = 0;
        while(mp.find(curr) != mp.end()){
            for(int& num: mp[curr]){
                res.push_back(num);
            }
            curr++;
        }
        return res;
    }
};
