class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // edges = prerequisites
        vector<vector<int>>adj(numCourses);
        for(auto& p: prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        
        vector<vector<bool>>can(numCourses,vector<bool>(numCourses, false));
        for(int i = 0; i < numCourses; i++){
            dfs(i, i, adj, can);
        }
        vector<bool>res;
        for(auto& q: queries){
            res.push_back(can[q[0]][q[1]]);
        }
        return res;
    }
    void dfs(int start, int end, vector<vector<int>>& adj, vector<vector<bool>>& can){
        if(can[start][end]) return;
        can[start][end] = true;
        for(int& n: adj[end]){
            dfs(start, n, adj, can);
        }
    }
};
