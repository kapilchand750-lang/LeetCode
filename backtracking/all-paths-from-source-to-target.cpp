class Solution {
    public:
        vector<vector<int>>ans;
            
        void dfs(int node, vector<vector<int>>&graph, vector<int>&temp){

            if(node == graph.size()-1){
                ans.push_back(temp);
                return;
            }

            for(auto ngh : graph[node]){
                temp.push_back(ngh);
                dfs(ngh, graph, temp);
                temp.pop_back();
            }
        }
        
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<int>temp;
            int V = graph.size();
            temp.push_back(0);
            
            dfs(0, graph, temp);
            temp.pop_back();

            return ans;
    }
};
