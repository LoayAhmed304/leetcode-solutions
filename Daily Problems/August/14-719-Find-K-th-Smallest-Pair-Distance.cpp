class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<int> d(n*(n-1)/2);
        int index=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++)
                d[index++]=abs(nums[i]-nums[j]);
        }
        nth_element(d.begin(), d.begin()+(k-1), d.end());
        return d[k-1];
    }
};

// To be refactored
