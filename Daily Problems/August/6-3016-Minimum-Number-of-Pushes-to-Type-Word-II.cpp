class Solution {
public:
    int minimumPushes(string word) {
        map<char, int>mp;

        for(auto& i: word){ 
            mp[i]++;
        }
        vector<pair<char, int>>charvec(mp.begin(), mp.end());
        auto comparison  = [&](auto a,auto b) {return a.second>b.second;};
        sort(charvec.begin(), charvec.end(), comparison);

        int z = 0;
        int res=0;
        int current=1;
        for(auto& i: charvec){
            if(z >= 8 && z % 8 == 0) current++;
            res +=  current * i.second;
            ++z;
        }

        return res;
    }
};