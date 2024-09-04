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

	void Union(int x, int y) {		// Log(N)
		int rootX = find(x);
		int rootY = find(y);

		if (rootX == rootY) return;

		if (rank[rootX] > rank[rootY])
			root[rootY] = rootX;
		else if (rank[rootY] > rank[rootX])
			root[rootX] = rootY;
		else {
			root[rootY] = rootX;
			++rank[rootX];
		}
		--n;
	}

	bool connected(int x, int y) {	// Log(N)
		return find(x) == find(y);
	}
};

class Solution{
public:
int earliestMoment(vector<vector<int>>logs, int N){
  UnionFind uf(n);
  
	for (int i = 0; i < n; i++) {
		uf.add(i);
	}

	for (auto& log : logs) {
		uf.Union(log[1], log[2]);
		if (uf.n == 1)
			return log[0];
	}
  
	return -1;
}
};
