class Solution {
private:
    class UnionFind{
    private:
        unordered_map<int, int> root;
        unordered_map<int, int> rank;
    public:
        int find(int x){
            if(root.find(x) == root.end()){
                root[x] = x;
                rank[x] = 1;
            }
            if(x == root[x]) return x;
            return root[x] = find(root[x]);
        }

        void unionSet(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY) return;

            if(rank[rootX] > rank[rootY]){
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }else{
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
        int height(){
            int maxRank = 0;
            for(auto& el: rank){
                maxRank = max(maxRank, el.second);
            }
            return maxRank;
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        UnionFind uf;
        unordered_set<int>numSet(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            uf.find(nums[i]);
        }

        for(int num: nums){
            if(numSet.find(num+1) != numSet.end()){
                if(uf.find(num + 1) != uf.find(num)){
                    uf.unionSet(num, num + 1);
                }
            }
        }

        return uf.height();
    }
};
