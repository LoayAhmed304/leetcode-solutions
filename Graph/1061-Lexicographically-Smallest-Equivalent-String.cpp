class UnionFind {
private:
	unordered_map<char, char> root;
public:

	void add(char x) {
		if (root.find(x) == root.end())
			root[x] = x;
	}
	char find(char x) {				// Log(N)
		if (root.find(x) == root.end() || x == root[x]) return x;

		return root[x] = find(root[x]);
	}

	void Union(char x, char y) {		// Log(N)
		char rootX = find(x);
		char rootY = find(y);

		if (rootX == rootY) return;

		if (rootX < rootY)
			root[rootY] = rootX;
		else if (rootY < rootX)
			root[rootX] = rootY;
	}
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        UnionFind uf;

        for(int i =0; i < n; i++){
            uf.add(s1[i]);
            uf.add(s2[i]);
        }

        for(int i = 0; i < n; i++){
            uf.Union(s1[i], s2[i]);
        }

        string res = "";
        for(char& c: baseStr){
            res += uf.find(c);
        }
        return res;
    }
};
