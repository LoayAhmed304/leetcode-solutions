class Solution {
public:
    long long coloredCells(int n) {
        return (long long)n * n + (long long)(n-1) * (n-1);
    }
};
