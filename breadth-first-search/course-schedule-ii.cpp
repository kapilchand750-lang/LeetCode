class Solution {
public:

    bool dfs(int src, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&stk, vector<bool>&path){
        visited[src] = true;
        path[src] = true;
        for(auto neighbor : adj[src]){
            if(!visited[neighbor]){
                if(dfs(neighbor, adj, visited, stk, path)) 
                    return true; //cycle detected
            }
            else if(path[neighbor]) return true; //cycle detected
        }
        path[src]=false;
        stk.push_back(src);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto edge : prerequisites){
            int v = edge[0];
            int u = edge[1];
            adj[u].push_back(v);
        }

        vector<bool>path(numCourses, false);
        vector<bool>visited(numCourses, false);
        vector<int>stk;
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, stk, path))
                    return {};
            }
        }
        reverse(stk.begin(), stk.end());
        return stk;
    }
};