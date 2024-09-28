class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        for(int i =0; i<nums.size() -3; i++){
            for(int j = i+1; j<nums.size() - 2; j++){
                for(int k = j+1; k < nums.size() -1; k++){
                    for(int x = k+1; x<nums.size(); x++){
                        if(nums[i] + nums[j] + nums[k] == nums[x])
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
