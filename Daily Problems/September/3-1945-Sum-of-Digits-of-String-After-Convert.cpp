class Solution {
public:
    int getLucky(string s, int k) {
        string all = "";

        for(int i = 0; i < s.size(); i++){
            int dig = s[i] - 'a' + 1;
            all += to_string(dig);
        }
        int temp=0;
        for(int i = 0; i < k; i++){
            temp = 0;
            for(auto& ch : all){
                temp += ch - '0';
            }
            all = to_string(temp);
        }
        return temp;

    }
};
