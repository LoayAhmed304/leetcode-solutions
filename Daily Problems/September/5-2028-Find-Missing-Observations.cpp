class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>res;
        int sum = 0;
        for(auto& roll:rolls){
            sum += roll;
        }
        for(int i =0; i<n; i++){
            res.push_back(6);
        }
        sum += 6 * n;
        
        int i = 0;
        while (float(sum/float(n+rolls.size())) != mean && i < n){
            if(res[i] > 1){
                 res[i]--;
                 sum--;
            }
            else{ 
                i++;
            }
        }
        if(float(sum/float(n+rolls.size())) != mean) return {};
        return res;
    }
};
