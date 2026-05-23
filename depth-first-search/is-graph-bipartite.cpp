class Solution {

    private:
    bool dfs(int src, vector<vector<int>>&adj, vector<int>&color){ //in this i am giving parent color but child index
        for(auto ngh : adj[src]){
            if(!color[ngh]){
                color[ngh] = -color[src];      //coloring adjacent nodes with opposite color
                if(!dfs(ngh, adj, color))
                    return false;
            }
            else if(color[ngh] == color[src]) //not if neighbor has same color as source
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V, 0); // All nodes are unvisted(color : 0)
        for(int i = 0; i<V; i++){
            if(!color[i]){
                color[i] = 1;
                if(!dfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};