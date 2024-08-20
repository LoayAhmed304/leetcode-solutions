class Solution {
public:
    int minSteps(int n) {
        int res=0;
        int factor =2;

        while(n>1){
            while(n % factor == 0){
                res += factor;
                n /= factor;
            }
            factor++;
        }

        return res;
    }
};
