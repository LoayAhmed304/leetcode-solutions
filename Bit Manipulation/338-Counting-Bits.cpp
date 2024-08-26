class Solution {
public:
    int getOnes(int x){
        int count = 0;
        while(x){
            if(x&1 == 1) ++count;
            x = x >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i =0; i<=n; i++){
            res.push_back(getOnes(i));
        }
        return res;
    }
};


//// Another code using dynamic programming
/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;
        for(int i = 1; i<=n; i++){
            if(offset * 2 == i)
                offset = i;
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }
};
*/