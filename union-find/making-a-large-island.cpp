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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU dsu(n * m);

        int dir[][2] = {{-1,0},{0,1},{1,0},{0,-1}};

        // Step 1: connect all 1s
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int nr = i + dir[k][0];
                        int nc = j + dir[k][1];

                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                            int node = i*m + j;
                            int adjNode = nr*m + nc;
                            dsu.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        int maxi = 0;
        int zeroCount = 0;

        // Step 2: try converting each 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    zeroCount++;

                    unordered_set<int> st;
                    int ans = 1;

                    for(int k = 0; k < 4; k++){
                        int nr = i + dir[k][0];
                        int nc = j + dir[k][1];

                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                            int parent = dsu.findParent(nr*m + nc);

                            if(st.find(parent) == st.end()){
                                st.insert(parent);
                                ans += dsu.size[parent];
                            }
                        }
                    }

                    maxi = max(maxi, ans);
                }
            }
        }

        return (zeroCount > 0) ? maxi : n * m;
    }
};