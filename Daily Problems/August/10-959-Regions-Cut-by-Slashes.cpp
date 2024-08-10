// This problem is solved with the help of Geeks for Geeks' beautiful introduction
// To DisJoin sets (Union-Find algorithm)
// https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/

// In addition to Nideesh Terapalli's youtube tutorial approaching this problem
// https://www.youtube.com/watch?v=tIZkh7mpIDo

// DisjSet class will be used in future problems with similar approaches

class DisjSet{
    int *rank, *parent, n;
    public:
    DisjSet(int n){
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet(){
        for(int i =0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y){
        int xset = this->find(x);
        int yset = this->find(y);

        if (xset == yset) return;
        this->parent[xset] = yset;
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        DisjSet uf(N*N*4);
        for(int i =0; i<N; i++){
            for(int j =0; j<N; j++){
                char c = grid[i][j];
                int root = (i*N + j) * 4;
                if(c != '\\'){
                    uf.Union(root, root+1);
                    uf.Union(root+2, root+3);
                }
                if (c!='/'){
                    uf.Union(root, root+2);
                    uf.Union(root+1, root+3);
                }
                // If its an empty space, both will be unioned
                // So it will be 1 set with 1 representative
                
                // Down
                if(i+1 < N){
                    uf.Union(root+3, root+(4*N) + 0);
                }

                // Up
                if(i-1 >=0){
                    uf.Union(root, root-(4*N) + 3);
                }

                // Right
                if(j+1 < N){
                    uf.Union(root+2, (root + 4) + 1);
                }
                
                // Left
                if(j-1 >= 0){
                    uf.Union(root+1, (root-4) +2);
                }

            }
        }
        int res =0;
        for(int i =0; i<N*N*4; i++){
            if(i == uf.find(i)){
                res++;
            }
        }
        
        return res;
    }
};