class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>mp;
        int n = target.size();
        
        for(int i=0; i<n; i++)
        {
            mp[target[i]]++;
        }

        for(auto i: arr){
            mp[i]--;
        }

        for(auto i: mp)
        {
            if (i.second !=0) return false;
        }

        return true;
    }
};