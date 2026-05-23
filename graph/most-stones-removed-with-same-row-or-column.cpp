class DSU{
public:
    vector<int> parent, rank, size;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int x){
        if(parent[x] != x){
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu]; 
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto stone : stones){
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DSU dsu( (maxCol + 1) + (maxRow + 1) );

        unordered_set<int>nodes;

        int offset = maxRow + 1;
        for(auto stone : stones){
            int rowNode = stone[0];
            int colNode = stone[1] + offset;
            dsu.unionBySize(rowNode, colNode);
            nodes.insert(rowNode);
            nodes.insert(colNode); 
        }

        int components = 0;
        for(auto node : nodes){
            if(dsu.findParent(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};