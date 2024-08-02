class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int windowSize =0;

        for(int i =0; i<n; i++){
            windowSize += nums[i];
        }

        if(windowSize == n || !windowSize) return 0;

        int windowOnes=0;
        for(int i =0; i<windowSize; i++) // calculate initial ones in the window
        {
            windowOnes += nums[i];
            nums.push_back(nums[i]); // appending the first window size elements to check for circular
        }

        int L =0, R=windowSize-1;
        int maxOnes = 0;
        while(R < n+windowSize-1){
            if(nums[L++] == 1) windowOnes--;
            if(nums[++R] == 1) windowOnes++;
            maxOnes = max(maxOnes, windowOnes);
        }

        return windowSize - maxOnes;
    }
};