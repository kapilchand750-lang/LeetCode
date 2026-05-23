class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>map;
        for(auto ch : s)
            map[ch]++;

        priority_queue<pair<int, char>>pq;
        
        string t = "";
        for(auto p : map)
            pq.push({p.second, p.first});

        while(!pq.empty()){
            auto node  = pq.top();
            pq.pop();
            int freq = node.first;
            char c = node.second;

            t+= string(freq, c);
        }
        return t;
    }
};