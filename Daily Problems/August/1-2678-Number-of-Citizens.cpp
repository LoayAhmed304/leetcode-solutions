class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int counter =0;
        for(int i =0; i<details.size(); i++){
            
            if(details[i][11] -'0' >6 || (details[i][11] -'0' ==6 && details[i][12] > '0'))
                counter++;
        }
        return counter;
    }
};