class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int V = points.size();

        vector<vector<pair<int, int>>>graph(V);

        for(int i = 0; i<V; i++){
            for(int j = i+1; j<V; j++){
                int x1 = points[i][0];
                int x2 = points[j][0];

                int y1 = points[i][1];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});

            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    
    vector<bool>vst(V);
    pq.push({0, 0});
    
    int totalCost = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int node = it.second;
        int weight = it.first;
        
        if(vst[node]) continue;
        
        vst[node] = true;
        
        totalCost += weight;
        
        for(auto ngh : graph[node]){
            int adjNode = ngh.first;
            int adjWeight = ngh.second;
            if(!vst[adjNode]){
                pq.push({adjWeight, adjNode});
            }
        }
    }
    
    return totalCost;
    }
};