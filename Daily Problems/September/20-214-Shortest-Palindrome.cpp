class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.size();
        string reversedString = s;
        reverse(reversedString.begin(), reversedString.end());

        for(int i = 0; i < length; ++i){
            if (!memcmp(s.c_str(), reversedString.c_str() + i, s.size() - i)){
                return reversedString.substr(0,i) + s;
            }
        }
        return reversedString + s;
    }
};
