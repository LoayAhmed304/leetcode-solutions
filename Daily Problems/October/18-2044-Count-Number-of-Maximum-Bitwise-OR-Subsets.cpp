class Solution {
public:
    int ArrOR(vector<int>& arr){
        int OR = 0;
        for(int i =0; i<arr.size(); i++){
            OR |= arr[i];
        }
        return OR;
    }
    void countRec(const vector<int>&nums, const int& maxOR,  int index, vector<int>& cur, int& res){
        if(index >= nums.size()) {
            if(ArrOR(cur) == maxOR){
                res++;
            }
            return;
        }
        
        cur.push_back(nums[index]);
        countRec(nums, maxOR, index + 1, cur, res);
        cur.pop_back();
        countRec(nums, maxOR, index + 1, cur, res);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int i =0; i<nums.size(); i++){
            maxOR |= nums[i];
        }
        int res = 0;
        vector<int>cur;
        countRec(nums, maxOR, 0,cur, res);
        return res;
    }
};
