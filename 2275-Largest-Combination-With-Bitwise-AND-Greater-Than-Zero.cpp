int largestCombination(vector<int>& candidates) {
        int res = INT_MIN;
        for(int i = 0; i < 24; i++){
            int cur = 0;
            for(int j = 0; j < candidates.size(); j++)
                if((candidates[j] & (1 << i)) != 0) cur++;
            res = max(cur, res);
        }
        return res;
    }
};
