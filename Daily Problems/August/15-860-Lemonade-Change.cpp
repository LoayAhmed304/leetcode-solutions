class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>cur;

        for(auto& bill: bills){
            if(bill == 5){
                cur[5]++;
            }
            else if(bill == 10){
                if(!cur[5])return false;
                cur[5]--;
                cur[10]++;
            }else{
                if(cur[10] && cur[5]){
                    cur[10]--;
                    cur[5]--;
                }else if(cur[5] >= 3){
                    cur[5] -= 3;
                }else return false;
            }
        }
        return true;
    }
};
