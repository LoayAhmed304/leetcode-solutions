class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> tempLower;
        vector<int> tempBigger;
        int eq = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <pivot) tempLower.push_back(nums[i]);
            else if(nums[i] > pivot) tempBigger.push_back(nums[i]);
            else eq++;
        }
        vector<int>res;
        for(int i = 0; i<tempLower.size(); i++){
            res.push_back(tempLower[i]);
        }
        while(eq--){
            res.push_back(pivot);
        }
        for(int i = 0; i<tempBigger.size(); i++){
            res.push_back(tempBigger[i]);
        }
        return res;

    }
};
