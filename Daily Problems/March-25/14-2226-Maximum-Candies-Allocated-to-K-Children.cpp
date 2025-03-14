class Solution {
public:
    bool canSplit(vector<int>& candies, int x, long long& k){
        long long res = 0;
        for(int i = 0; i < candies.size(); i++){
            res += candies[i] / x;
        }
        if(res >= k) return true;
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int x = 1;
        int l = 0, r = *max_element(candies.begin(), candies.end());
        int res = 0;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(canSplit(candies, mid, k)){
                l = mid;
            }else
                r = mid - 1;
        }
        return l;
    }
};
