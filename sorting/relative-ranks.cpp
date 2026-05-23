class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
       int n = score.size();
       vector<string> result;
       for(int i = 0; i<n; i++){
        pq.push({score[i],i});
       }

       vector<string>ans(n);
       int rank =1;
       while(!pq.empty()){
        int pos = pq.top().second;
        pq.pop();
        if(rank ==1) ans[pos] = "Gold Medal";
        else if(rank ==2) ans[pos] = "Silver Medal";
        else if(rank ==3) ans[pos] = "Bronze Medal";
        else ans[pos] = to_string(rank);
       rank++;
    }
       return ans;
    }
};