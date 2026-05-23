class Solution {
    private: 
    bool dfs(int src, vector<vector<int>>&adj, vector<int>&vst, vector<int>&pathvst){
        vst[src] = 1;
        pathvst[src] = 1;
        for(auto ngh : adj[src]){
            if(!vst[ngh]){
                if(dfs(ngh, adj, vst, pathvst)) return true;
            }
            else if(pathvst[ngh]) return true;
        }
        pathvst[src] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto edge : prerequisites){
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
        }
        int V= numCourses;
        vector<int>vst(V,0);
        vector<int>pathvst(V, 0);
        for(int i =0; i<V; i++){
            if(!vst[i]){
                if(dfs(i, adj, vst, pathvst))
                return false;
            }
        }
        return true;
    }
};