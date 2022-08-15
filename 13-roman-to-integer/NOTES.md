class Solution {
public:
int romanToInt(string s) {
unordered_map<int,int> m;
int n = s.length();
m['I'] = 1;
m['V'] = 5;
m['X'] = 10;
m['L'] = 50;
m['C'] = 100;
m['D'] = 500;
m['M'] = 1000;
int num = m[s[0]];
for(int i=1;i<n;i++)
{
if(m[s[i-1]]<m[s[i]])
num+=m[s[i]]-2*m[s[i-1]];
else
num+=m[s[i]];
}
return num;
}
};