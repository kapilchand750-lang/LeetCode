class Solution {
public:
    bool isVowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U' ) return true;
        return false;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            while(!isVowel(s[i]) && i<j) i++;
            while(!isVowel(s[j]) && j>i) j--;
            if(isVowel(s[i]) && isVowel(s[j])) swap(s[i++], s[j--]);
        }
        return s;
    }
};