class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int dist = 0;
        int smallest = arrays[0][0];
        int biggest = arrays[0][arrays[0].size()-1];
        
        for(int i = 1; i < m; i++){
            dist = max(dist, abs(arrays[i][arrays[i].size()-1] - smallest));
            dist = max(dist, abs(arrays[i][0] - biggest));
            
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i][arrays[i].size()-1]);
        }

        return dist;
    }
};
