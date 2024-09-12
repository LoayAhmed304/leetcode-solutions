class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());

        int l = 1;
        int r = piles[n-1];
        int totalTime = l;
        while(l<=r){
            long long res=0;
            int mid = (l+r) / 2;

            for(int i =0; i<n; i++){
                res += ceil(double(piles[i]) / mid);
            }
            
            if(res <= h){
                r = mid-1;
                totalTime = mid;
            }
            else
                l = mid+1;
        }
        return totalTime;
    }
};
