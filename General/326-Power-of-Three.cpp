class Solution {
public:
    bool powerRec(long long n, long long cur, long long res){
        if(n == res) return true;
        if(res > n) return false;

        return powerRec(n, cur + 1, pow(3, cur));
    }
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        return powerRec(n, 0, 0);
    }
};
