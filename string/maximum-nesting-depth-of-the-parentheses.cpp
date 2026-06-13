class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int n = s.size(); 
        int depth = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            depth = max(depth, cnt);
        }
        return depth;
    }
};