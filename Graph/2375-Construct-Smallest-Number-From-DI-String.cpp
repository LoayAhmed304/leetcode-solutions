class Solution {
public:
    string smallestNumber(string pattern) {
        string res = "";
        int j =0;

        for(int i = 0; i<=pattern.size(); i++){
            res += to_string(i + 1);
            if(i == pattern.size() || pattern[i] == 'I'){
                reverse(res.begin() + j, res.end());
                j = i + 1;
            }
        }
        return res;

    }
};
