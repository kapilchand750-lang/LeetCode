class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool sign = true;
        long long num = 0;

        int i = 0;

        while(i<n && s[i]==' ')
            i++;
        
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign = false;
            i++;
        }

        while(i<n && s[i]>='0' && s[i]<='9'){
            num = num*10 + (s[i]-'0');

            if(sign && num>INT_MAX) return INT_MAX;
            if(!sign && num>(long long)INT_MAX+1) return INT_MIN; 
            i++;
        }

        return (sign)?(int)num : (int)(-num);
    }
};