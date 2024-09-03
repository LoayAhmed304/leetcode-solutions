class Solution {
private:
    class UnionFind{
        private:
            vector<int> root;
            vector<int> rank;
        public:
            UnionFind(int size): root(size), rank(size){
                
                for(int i = 0; i<size; i++){
                    root[i] = i;
                    rank[i] = 1;
                }
            }

            int find(int x){
                if(x == root[x]) return x;
                return root[x] = this->find(root[x]);
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
            }
            bool connected(int x, int y){
                return find(x) == find(y);
            }
        };

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);

        for(auto& edge: edges){
            uf.unionSet(edge[0], edge[1]);
        }

        return uf.connected(source, destination);
    }
};
