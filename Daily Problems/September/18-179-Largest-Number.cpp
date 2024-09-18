class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto compare = [&] (int a, int b){
            string strA = to_string(a);
            string strB = to_string(b);

            return (strA + strB > strB + strA);
        };
        sort(nums.begin(), nums.end(), compare);

        string res = "";
        for (auto &num: nums){
            res += to_string(num);
        }
        
        if(res[0] == '0') return "0";
        return res;
    }
};
