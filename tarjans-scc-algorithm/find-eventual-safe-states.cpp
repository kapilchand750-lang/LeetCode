class Solution {
private:
    bool dfs(int src, vector<vector<int>>&adj, vector<int>&state){
        if(state[src]==1) return true;
        if(state[src]==2) return false;

        state[src] = 1;
        for(auto ngh : adj[src]){
            if(state[ngh]==2) continue;
            if(dfs(ngh, adj, state)) 
                return true;
        }

        state[src] = 2;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>state(V, 0);
        vector<int>safe;
        for(int i = 0; i<V; i++){
            if(!dfs(i, graph, state)){
                safe.push_back(i);
            }
        }
        return safe;
    }
};