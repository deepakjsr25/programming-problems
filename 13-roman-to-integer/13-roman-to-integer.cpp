class Solution {
public:
    int romanToInt(string s) {
        int m[27]={0};
        int n = s.length();
        int sum=0;
        
        m['I'-'A'] = 1;
        m['V'-'A'] = 5;
        m['X'-'A'] = 10;
        m['L'-'A'] = 50;
        m['C'-'A'] = 100;
        m['D'-'A'] = 500;
        m['M'-'A'] = 1000;
        
        sum=m[s[0]-'A'];
        for(int i=1;i<n;i++){
            sum+=m[s[i]-'A'];
            if((m[s[i]-'A']>m[s[i-1]-'A'])){
                sum-=2*m[s[i-1]-'A'];
            }
        }
        
        return sum;
    }
};