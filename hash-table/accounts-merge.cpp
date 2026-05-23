class DSU {
    vector<int> parent, rankArr;

public:
    DSU(int n) {
        parent.resize(n);
        rankArr.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }

    void unionByRank(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb) return;

        if (rankArr[pa] > rankArr[pb]) parent[pb] = pa;
        else if (rankArr[pb] > rankArr[pa]) parent[pa] = pb;
        else {
            parent[pb] = pa;
            rankArr[pa]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> mapMailNode;

        // Step 1: Union accounts with same email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    dsu.unionByRank(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group emails by parent
        vector<vector<string>> mergeMail(n);

        for (auto &it : mapMailNode) {
            string mail = it.first;
            int parent = dsu.findParent(it.second);
            mergeMail[parent].push_back(mail);
        }

        // Step 3: Build result
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergeMail[i].empty()) continue;

            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;

            // Use parent for name (safe)
            temp.push_back(accounts[i][0]);

            for (auto &mail : mergeMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};