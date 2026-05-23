class Solution {
public:
    void dfs(int start, vector<vector<int>>& list, vector<bool>&visited){
        visited[start] = true;
        for(int j = 0; j<list.size(); j++){
            if(list[start][j] && !visited[j]){
                dfs(j, list, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool>visited(V, false);
        int cnt = 0;
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, isConnected, visited);
            }
        }
        return cnt;
    }
};