class Solution {
    vector<vector<int>>all;

    void solve(int k, int n, int used, int sum, vector<int>&temp, int ele){
        if(sum==n && used==k){
            all.push_back(temp);
            return;
        }
        if(sum==n && used<k) return;

        if(used==k || sum>n || ele>9) return;
        // int newUsed = used+1;
        temp.push_back(ele);
        solve(k, n, used+1, sum + ele, temp, ele+1);
        temp.pop_back();
        solve(k, n, used, sum, temp, ele+1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k, n, 0, 0, temp, 1);
        return all;
    }
};