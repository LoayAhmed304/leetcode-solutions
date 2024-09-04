
class Solution {
private:
	class UnionFind {
	private:
		unordered_map<int, int> root;
		unordered_map<int, int> rank;
	public:
        void add(int x){
            if(root.find(x) == root.end()){
                root[x] = x;
                rank[x] = 0;
            }
        }
		int find(int x) {				// Log(N)
			if (x == root[x]) return x;

			return root[x] = find(root[x]);
		}


		bool Union(int x, int y) {		// Log(N)
			int rootX = find(x);
			int rootY = find(y);

			if (rootX == rootY) return false; // Cycle

			if (rank[rootX] > rank[rootY])
				root[rootY] = rootX;
			else if (rank[rootY] > rank[rootX])
				root[rootX] = rootY;
			else {
				root[rootY] = rootX;
				++rank[rootX];
			}
            return true;
		}

		bool connected(int x, int y) {	// Log(N)
			return find(x) == find(y);
		}
	};
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

		UnionFind uf;
        for(int i =0; i<n; i++){
            uf.add(i);
        }

		for (auto& edge : edges) {
			if(!uf.Union(edge[0], edge[1])) return false;
		}

        int root = uf.find(0);
        for(int i =1; i<n; i++){
            if(uf.find(i) != root)
                return false;
        }
		return true;
    }
};
