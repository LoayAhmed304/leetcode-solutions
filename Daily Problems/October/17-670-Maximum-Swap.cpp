class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string temp = s;
        string maximum = s;
        for(int i =0; i < s.size() - 1; i++){
            for(int j =i+1; j<s.size(); j++){
                s = temp;
                swap(s[i], s[j]);
                if(stoi(s) >= stoi(maximum)){
                    maximum = s;
                    swap(s[i], s[j]);
                }
            }
        }
        return stoi(maximum);
   }
};
