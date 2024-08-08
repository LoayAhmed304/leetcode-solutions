class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int step = 1;
        res.push_back({rStart,cStart});

        while(res.size() < rows*cols){
            for(int i =0; i<step; i++){
                cStart++;

                if(rStart < rows && rStart >=0 && cStart < cols && cStart >=0) res.push_back({rStart, cStart});
            }
            for(int i =0; i<step; i++){
                rStart++;
                if(rStart < rows && rStart >=0 && cStart < cols && cStart >=0) res.push_back({rStart, cStart});
            }
            step++;
            for(int i =0; i<step; i++){
                cStart--;
                if(rStart < rows && rStart >=0 && cStart < cols && cStart >=0) res.push_back({rStart, cStart});
            }
            for(int i =0; i<step; i++){
                rStart--;
                if(rStart < rows && rStart >=0 && cStart < cols && cStart >=0) res.push_back({rStart, cStart});
            }
            step++;
        }
        return res;
    }
};