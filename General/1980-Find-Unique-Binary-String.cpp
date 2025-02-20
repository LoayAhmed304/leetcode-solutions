class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>numbers;
        for(int i =0; i< nums.size(); i++){
            numbers.insert(stoi(nums[i], 0, 2));
        }

        for(int i =0; i <= nums.size(); i++){
            if(numbers.count(i) == 0){
                string res = bitset<16>(i).to_string();
                return res.substr(16 - nums.size());
            }
        }

        return "";
    }
};
