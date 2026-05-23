class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int adjMatanceThreshold) {
        vector<vector<int>>adjMat(n, vector<int>(n, INT_MAX));

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjMat[u][v] = w;
            adjMat[v][u] = w;
        }

        for(int i = 0; i<n; i++){
            adjMat[i][i] = 0;
        }

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(adjMat[i][k]!=INT_MAX && adjMat[k][j]!=INT_MAX){
                        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                    }
                }
            }
        }

        int cityNo = -1;
        int cntCity = n;
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(i!=j && adjMat[i][j]<=adjMatanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cntCity){
                cntCity = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};