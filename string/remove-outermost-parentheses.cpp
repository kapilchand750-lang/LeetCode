class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        string temp;
        for(int i = 0; i<n; i++){
            if(s[i]==')') cnt--;
            if(cnt) temp += s[i];
            if(s[i]=='(') cnt++;
        }
        return temp;
    }
};