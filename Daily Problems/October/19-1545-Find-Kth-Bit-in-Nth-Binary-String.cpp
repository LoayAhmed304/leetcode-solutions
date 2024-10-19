class Solution {
public:
    string invert(string& str){
        for(int i =0; i<str.size(); i++){
            str[i] = str[i] == '1'? '0' : '1';
        }
        return str;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 1; i < n; i++){
            string reversedS = s;
            reverse(reversedS.begin(), reversedS.end());

            s = s + "1" + invert(reversedS);
        }
        return s[k-1];
    }
};
