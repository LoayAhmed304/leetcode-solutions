class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int>mp;

        for(int i = 0; i<nums1.size(); i++){
            mp[nums1[i][0]] += nums1[i][1];
        }

        for(int i = 0; i<nums2.size(); i++){
            mp[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>>res;

        for(auto pair: mp){
            res.push_back({pair.first, pair.second})    ;
        }
        auto compare = [&](vector<int> a, vector<int>b){
            return a[0] < b[0];
        };
        // sort(res.begin(), res.end(), compare);
        return res;
    }
};
