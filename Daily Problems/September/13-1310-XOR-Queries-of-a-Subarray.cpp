class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;

        for(auto& q: queries){
            int temp = 0;
            for(int i = q[0]; i <= q[1]; i++){
                temp ^= arr[i];
            }
            res.push_back(temp);
        }
        return res;
    }
};
