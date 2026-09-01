class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0; 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size()-1;
        int j = s.size()-1;
        for(; i>=0 && j>=0; i--){
             if(s[j]>=g[i]){
                count++;
                j--;
             }
        }
        return count;
    }
};