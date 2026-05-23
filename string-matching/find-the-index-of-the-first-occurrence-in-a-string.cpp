class Solution {
public:
    vector<int> LPS(string needle){
        int m = needle.size();
        int len = 0;
        vector<int>lps(m, 0);

        for(int i = 1; i<m; i++){
            while(len>0 && needle[len]!=needle[i])
                len = lps[len-1];
            if(needle[len]==needle[i])
                len++;
            lps[i] = len;
        }

        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int>lps = LPS(needle);
        int len = 0;
        for(int i = 0; i<n; i++){
            while(len>0 && needle[len]!=haystack[i])
                len = lps[len-1];
            if(needle[len]==haystack[i])
                len++;
            if(len==m)
                return i-m+1;
        }
        return -1;
    }
};