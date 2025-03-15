class Solution {
public:
    bool isVowel(char t){
        return t=='a' || t == 'i' || t == 'o' || t == 'u' || t=='e';
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int>current;
        long long res = 0;
        int cons = 0;

        vector<int>nextCons(word.size());
        int nextIndex = word.size();
        for(int i = word.size() - 1; i >=0; i--){
            nextCons[i] = nextIndex;
            if(!isVowel(word[i]))
                nextIndex = i;
        }

        int l=0, r=0;
        while(r < word.size()){
            if(isVowel(word[r])){
                current[word[r]]++;
            }else{
                cons++;
            }

            while(cons > k){
                if(isVowel(word[l])){
                    current[word[l]]--;
                    if(current[word[l]] <= 0) current.erase(word[l]);
                }else{
                    cons--;
                }
                l++;
            }
            while(current.size() == 5 && cons == k && l < word.size()){
                res += nextCons[r] - r;
                if(isVowel(word[l])){
                    current[word[l]]--;
                    if(current[word[l]] <= 0) current.erase(word[l]);
                }else{
                    cons--;
                }
                l++;
            }
            r++;
        }
        return res;
        
    }
};
