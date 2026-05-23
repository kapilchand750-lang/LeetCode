class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i<n; ){
            if(s[i]!=' '){
                int j = i+1;
                while(j<n && s[j]!=' ')
                    j++;
            cnt++;
            i = j;
            }else i++;
        }
        return cnt;
    }
};