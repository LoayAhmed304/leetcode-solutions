class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), long(0));
        k = k % sum;

        for(int i =0; i<n; i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return 0;
    }
};
