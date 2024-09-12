class Solution {
private:
    int maxMap(unordered_map<char, int>mp){
        int max_val = INT_MIN;
        for(auto &i: mp)
        {
            if(i.second > max_val)
                max_val = i.second;
        }
        return max_val;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>count;
        int res=0;
        int l=0;
        for(int r=0; r<s.size(); r++)
        {
            count[s[r]]++;
            while((r - l + 1 - maxMap(count)) > k)
            {
                count[s[l]]--;
                l++;
            }
            if((r - l + 1 )> res)
                res = r - l + 1;
        }
        return res;
    }
};
