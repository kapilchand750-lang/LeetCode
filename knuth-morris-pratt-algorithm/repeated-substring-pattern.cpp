class Solution {
private:
vector<int> LPS(string s){
    int k = 0;
    int n = s.size();
    vector<int>lps(n, 0);
    for(int i = 1; i<n; i++){
        while(k>0 && s[k]!=s[i])
            k = lps[k-1];
        if(s[k]==s[i])
            k++;
        lps[i] = k;
    }
    return lps;
}

public:
    bool repeatedSubstringPattern(string s) {
        vector<int>lps = LPS(s);
        int n = s.size();
        int maxi =lps[n-1];
        if(maxi>0 && (n%(n-maxi)==0)) return true;
        return false;
    }
};