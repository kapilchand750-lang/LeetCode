class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        int j = 0;
        int i = 0;
        while(j<m && i<n){
            if(s[i]==t[j])
                i++;
            j++;
        }

        return (i==n);
    }
};