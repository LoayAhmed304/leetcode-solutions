class Solution {
    private:
        class UnionFind{
          private:
            int* root;
            int* rank;
            int count;
          public:
            UnionFind(int size){
                root = new int[size];
                rank = new int[size];
                for(int i =0; i<size; i++){
                    root[i] = i;
                    rank[i] = 1;
                }
                count = size;
            }

            int find(int x){
                if(x == root[x]) return x;
                return root[x] = find(root[x]);
            }

            void unionSet(int x, int y){
                int rootX = find(x);
                int rootY = find(y);
                if(rootX == rootY) return;

                if(rank[rootX] > rank[rootY])
                    root[rootY] = rootX;
                else if (rank[rootY] > rank[rootX])
                    root[rootX] = rootY;
                else{
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
                --this->count;
            }
            int getCount(){
                return this->count;
            }
        };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]) uf.unionSet(i, j);
            }
        }
        
        return uf.getCount();
    }
};
