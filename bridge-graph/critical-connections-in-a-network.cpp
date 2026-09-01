class Solution {
public:
    int timer = 1;
    void dfs(int src, vector<vector<int>>&adj, int parent, vector<int>&vst, vector<int>&leastDis, vector<int>&disc, vector<vector<int>>&bridges){
        vst[src] = 1;
        leastDis[src] = timer;
        disc[src] = timer;
        timer++;

        for(auto ngh : adj[src]){
            if(ngh == parent) continue;
            if(!vst[ngh]){
                dfs(ngh, adj, src, vst, leastDis, disc, bridges);
                leastDis[src] = min(leastDis[src], leastDis[ngh]);

                if(leastDis[ngh]>disc[src]){
                    bridges.push_back({src, ngh});
                }
            }
            else {
                leastDis[src] = min(leastDis[src], disc[ngh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int>vst(n, 0);
        vector<vector<int>>bridges;
        vector<int>low(n, 0);
        vector<int>disc(n, 0);

        for(int i = 0; i<n; i++){
            if(!vst[i]){
                dfs(0, adj, -1, vst, low, disc, bridges);
            }
        }

        return bridges;
    }
};