class Solution {
public:
    double powRec(double x, long long n){
        if(n == 1) return x;
        if(n == 0) return 1;
        if(x == 0) return 0;
        if(n % 2 == 0)
            return powRec(x * x, n / 2);
        else
            return x * powRec(x*x, n/2);
    }
    double myPow(double x, long long n) {
        double res = 1;
        if(n < 0){
            x = 1/x;
            n *= -1;
        }
        return powRec(x, n);
        
    }
};
