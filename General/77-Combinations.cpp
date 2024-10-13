class Solution {
public:
    void generate(const vector<int>& arr, int n, int k, int index, vector<int>&cur, vector<vector<int>>&res){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        if(index == arr.size()){
            return;
        }
        cur.push_back(arr[index]);
        generate(arr, n, k, index + 1, cur, res);
        cur.pop_back();
        generate(arr, n, k, index + 1, cur, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        for(int i =1; i<=n; i++){
            arr.push_back(i);
        }
        vector<vector<int>>res;
        vector<int>cur;
        generate(arr, n, k, 0, cur, res);
        return res;
    }
};
