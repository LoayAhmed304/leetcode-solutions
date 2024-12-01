class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i<s.size(); i++){
            
            int l = i;
            int r = i;

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res++;
                r++;
                l--;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res++;
                r++;
                l--;
            }
        }
        return res;
    }
};
