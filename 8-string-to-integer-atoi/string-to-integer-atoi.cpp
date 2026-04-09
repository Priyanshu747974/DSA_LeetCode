class Solution {
public:
    int myAtoi(string s) {
        long long final=0;
        int sign=1;
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-'||s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            final=final*10+(s[i]-'0');
            if(sign*final >= INT_MAX)return INT_MAX;
            if(sign*final <= INT_MIN)return INT_MIN;
            i++;
        }
        
        return sign*final;
    }
};