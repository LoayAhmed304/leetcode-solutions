class Solution {
public:
    vector<vector<int>>dp;
    bool rec(string s, string p, int i, int j){
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];

        bool same = i< s.size() && (s[i] == p[j] || p[j] == '.');
        if(j +1 < p.size() && p[j+1] == '*'){
            bool dont = rec(s, p, i, j+2);
            bool take = same && rec(s, p, i+1, j);
            return dp[i][j] = dont || take;
        }
        if(same)
            return dp[i][j] = rec(s, p, i+1, j+1);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        return rec(s, p, 0, 0);
    }
};
