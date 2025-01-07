class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>result;
        for(string& pattern: words){
            vector<int>lps = computeLPS(pattern);

            for(string& text: words){
                if(text == pattern) continue;
                if(isSubstring(pattern, text, lps)) {
                    result.push_back(pattern);
                    break;
                }
            }
        }
        return result;
    }
    vector<int> computeLPS(string& pattern){
        vector<int>lps(pattern.size(), 0);
        int currentIndex = 1;
        int len = 0;
        
        while(currentIndex < pattern.size()){
            if(pattern[currentIndex] == pattern[len]){
                lps[currentIndex++] = ++len;
            }else{
                if(len > 0) len = lps[len-1];
                else currentIndex++;
            }
        }
        return lps;
    }
    bool isSubstring(string& pattern, string& text, vector<int>& lps){
        int textIndex = 0;
        int patternIndex = 0;
        while(textIndex < text.size()){
            if(text[textIndex] == pattern[patternIndex]){
                textIndex++;
                patternIndex++;
                if(patternIndex == pattern.size()) return true;
            }else{
                if(patternIndex > 0){
                    patternIndex = lps[patternIndex-1];
                }else{
                    textIndex++;
                }
            }
        }
        return false;
    }

};
