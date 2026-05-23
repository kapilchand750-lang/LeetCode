class DSU{
    public:
    vector<int>parent, rank;
    DSU(int n){
        parent.resize(n, 0);
        rank.resize(n, 0);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }

    int findParent(int a){
        if(parent[a]!=a){
            parent[a] = findParent(parent[a]);
        }
        return parent[a];
    }

    void unionRank(int a, int b){
        int pa = findParent(a);
        int pb = findParent(b);

        if(pa == pb) return;

        if(rank[pa]>rank[pb]){parent[pb] = pa;}
        else if(rank[pb]>rank[pa]) {parent[pa] = pb;}
        else{
            rank[pa]++;
            parent[pb] = pa;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1) return -1;

        DSU dsu(n);
        int cntExtras = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(dsu.findParent(u)==dsu.findParent(v)){
                cntExtras++;
            }
            else {
                dsu.unionRank(u, v);
            }
        }

        int cntC = 0;
        for(int i = 0; i<n; i++){
            if(dsu.findParent(i)==i) cntC++;
        }

        int ans = cntC-1;

        if(cntExtras>=ans) return ans;
        return -1;

    }
};