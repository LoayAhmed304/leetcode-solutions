class Solution {
public:
    void numRec(string& tiles, int& sum, vector<bool>& used){
        sum++;

        for(int i = 0; i < tiles.size(); i++){
            if(used[i]) continue;
            if(i > 0 && tiles[i] == tiles[i-1] && !used[i-1]) continue;
            used[i] = true;
            numRec(tiles, sum, used);
            used[i] = false;
        }
        
    }
    int numTilePossibilities(string tiles) {
        int res = 0;
        sort(tiles.begin(), tiles.end());
        vector<bool>used(8, false);
        numRec(tiles, res, used);
        return res - 1;
    }
};
