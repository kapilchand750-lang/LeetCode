class DSU{
    vector<int>parent;
    public : 
    DSU(int n){
        parent.resize(n);

        for(int i = 0; i<n; i++)
            parent[i] = i; 
    }

    int findParent(int x){
        if(parent[x]!=x)
            return parent[x] = findParent(parent[x]);
        return parent[x];
    }

    void unionByParent(int x, int y){
        int px = findParent(x);
        int py = findParent(y);

        parent[py] = px;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(dsu.findParent(u)!=dsu.findParent(v)){
                dsu.unionByParent(u, v);
            }
            else{
                return edge;
            }
        }
        return {};
    }
};