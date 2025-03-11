class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>mp;
        int res = 0;
        int l=0, r = 0;
        while(r < s.size()){
            mp[s[r]]++;
            while(mp.size() == 3 && l < s.size()){
                res += s.size() - r;
                if(--mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return res;
    }
};
