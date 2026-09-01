class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='('){
                if(cnt)
                    temp +=s[i];
                cnt++;
            }else{
                cnt--;
                if(cnt)
                    temp +=s[i];
            }
        }
        return temp;
    }
};