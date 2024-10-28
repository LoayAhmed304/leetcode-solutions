class Solution {
public:
struct CompareByChar {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;  
    }
};
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, CompareByChar >pq;
        vector<char>v;
        for(int i =0; i<s.size(); i++){
            v.push_back(s[i]);
        }

        for(int i = 0; i<v.size(); i++){
            if(v[i] != '*') pq.push({v[i], i});
            else{
                pair<char, int>letter = pq.top();
                pq.pop();
                v[letter.second] = '-';
            }
        }
        string res = "";
        for(int i =0; i<v.size(); i++){
            if(v[i] != '-' && v[i] != '*') res += v[i];
        }
        return res;
    }
};
