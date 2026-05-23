class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;

            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1) return dis;

            for(int i = 0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEffort = max(abs(heights[r][c]-heights[nr][nc]), dis);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};