class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, vector<int>>mp;
        int res=0;
        int x = pick.size();
        for(auto& i: pick){
            mp[i[0]].push_back(i[1]);
        }

        for(auto& m: mp){
            int mostEl = m.first;
            int maxCount=0;
            if(m.first == 0){
                res++;
                continue;
            }
        unordered_map<int, int> freq;

            for(int i =0; i<m.second.size(); i++){
                freq[m.second[i]]++;
            }
            for(auto x: freq){
                if(x.second > maxCount){
                    mostEl = m.first;
                    maxCount = x.second;
                }
            }
            if(maxCount > mostEl)
                res++;
        }

        return res;
    }
};