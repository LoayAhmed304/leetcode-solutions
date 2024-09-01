class Solution {
public:
    string stringHash(string s, int k) {
        
        string res = "";

        for (int i = 0; i<s.size() - k + 1; i += k){
            int temp = 0;

            for(int j = i; j<k+i; j++){
                temp += s[j]-'a';
            }
            temp %= 26;
            temp += 'a';

            res += static_cast<char>(temp);
        }

        return res;
    }
};
