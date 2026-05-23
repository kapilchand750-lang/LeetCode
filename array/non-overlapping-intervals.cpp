class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int i = 0;
        for(auto time : intervals){
            int fi = time[1];
            pq.push({fi, i});
                        i++;
        }
        int current = pq.top().second;
        pq.pop();
        int activity = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int next = it.second;
            if(intervals[current][1]<=intervals[next][0]){
                activity++;
                current = next;
            }
        }
        return intervals.size() - activity;
    }
};