class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        

        int div = 1000;
        int res = 0;
        for(int i = 0; i<4; i++){
            res = res*10 + min(num1/div, min(num2/div, num3/div));

            num1 %= div;
            num2 %= div;
            num3 %= div;
            
            div /= 10;
        }
        return res;
    }
};
