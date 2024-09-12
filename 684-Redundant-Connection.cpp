class UnionFind {
private:
	unordered_map<int, int> root;
	unordered_map<int, int> rank;
public:
	int n;
	UnionFind(int n) : n(n) {

	}
	void add(int x) {
		if (root.find(x) == root.end()) {
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

		if (rootX == rootY) return false;

		if (rank[rootX] > rank[rootY])
			root[rootY] = rootX;
		else if (rank[rootY] > rank[rootX])
			root[rootX] = rootY;
		else {
			root[rootY] = rootX;
			++rank[rootX];
		}
		--n;
        return true;
	}
};

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size());

        // Initialize the parents/set
        for(int i = 0; i<edges.size(); i++){
            uf.add(i+1);
        }

        // Loop over every edge, return them if they're of the same parent (union returned false)
        for(auto &edge: edges){
            if(!uf.Union(edge[0], edge[1])) return {edge[0], edge[1]};
        }
        return {};
    }
};
