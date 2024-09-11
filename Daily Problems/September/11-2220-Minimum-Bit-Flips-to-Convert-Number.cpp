class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        while(start || goal){
            res += (start & 1) ^ (goal & 1); // Returns 1 if different bits, 0 if same
            
            start = start >> 1;
            goal = goal >> 1;
        }
        return res  ;
    }
};
