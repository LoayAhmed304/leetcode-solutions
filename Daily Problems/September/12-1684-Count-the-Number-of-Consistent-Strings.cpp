class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int>allowedMap; // To make the search easier
        int res = 0;
      
        for(int i =0; i<allowed.size(); i++){
            allowedMap[allowed[i]]++;
        }

        for(auto &word: words){
            bool cons = true;
          
            for(int i =0; i < word.size(); i++){
                if(allowedMap[word[i]] == 0){
                    cons = false;
                    break;
                }
            }
            if(cons) ++res;
        }
        return res;
    }
};
