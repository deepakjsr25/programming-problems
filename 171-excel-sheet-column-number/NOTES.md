class Solution {
public:
int titleToNumber(string str) {
int n = str.length();
return n==0?0:(titleToNumber(str.substr(0,n-1))*26 + (str[n-1] - 64));
}
};