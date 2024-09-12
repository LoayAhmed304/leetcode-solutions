class Solution {
public:
    int trailingZeroes(int n) {
        // Count the pairs (2 * 5) because that will add 1 zero to the result
        int count=0;

        while(n>=5){
            n /=5;
            count += n;
        }
        return count;
    }
};