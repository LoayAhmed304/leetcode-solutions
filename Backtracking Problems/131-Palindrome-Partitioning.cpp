class Solution {
public:
    bool isPalindrome(string& word, int left, int right){
        while(left < right)
            if(word[left++] != word[right--]) return false;
        return true;
    }

    void backtrack(vector<vector<string>>& res, vector<string>subset, string& s, int i){
        if(i >= s.length()) {
            res.push_back(subset);
            return;
        }

        for(int j = i; j<s.length(); j++){
            if(isPalindrome(s, i, j)){
                subset.push_back(s.substr(i, j-i+1));
                backtrack(res, subset, s, j+1);
                subset.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>subset;
        backtrack(res, subset, s, 0);
        return res;
    }
};
