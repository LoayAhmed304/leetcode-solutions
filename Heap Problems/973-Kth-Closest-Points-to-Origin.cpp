class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto compare = [](vector<int>& point1,vector<int>& point2){
            return point1[0] * point1[0] + point1[1] * point1[1] > point2[0] * point2[0] + point2[1] * point2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)>minHeap;

        for(auto& point: points){
            minHeap.push(point);
        }

        vector<vector<int>> res;
        for(int i =0; i<k; i++){
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }
};
