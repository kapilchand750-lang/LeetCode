class Solution {
    bool dfs(int node, int parentColor, vector<int>&color, vector<vector<int>>&adj){
        color[node] = (parentColor==1)?-1:1;

        for(auto ngh : adj[node]){
            if(!color[ngh]){
                if(!dfs(ngh, color[node], color, adj))
                    return false;
            }else if(color[ngh]==color[node]) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto edge : dislikes){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n+1, 0);
        for(int i = 1; i<=n; i++){
            if(color[i]) continue;
            if(!dfs(i, 1, color, adj))
                return false;
        }
        return true;
    }
};