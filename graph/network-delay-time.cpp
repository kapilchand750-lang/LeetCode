class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({w, v});
        }

        vector<int>dis(n+1, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        dis[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int weight = it.first;
            if(weight>dis[node]) continue;

            for(auto ngh : adj[node]){
                int adjNode = ngh.second;
                int adjWeight = ngh.first;
                int newWeight = adjWeight + weight;
                if(newWeight < dis[adjNode]){
                    dis[adjNode] = newWeight;
                    pq.push({newWeight , adjNode});
                }
            }
        }
        int ans = *max_element(dis.begin()+1, dis.end());
        return (ans==INT_MAX?-1: ans);
    }
};