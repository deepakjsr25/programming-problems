class Solution {
public:
int lengthOfLongestSubstring(string s) {
int len = s.length();
vector<int> cache(256,0);
int maxi_len = 0;
int l = 0,r=0;
while(r<len){
cache[s[r]]++;
while(cache[s[r]]>1){
cache[s[l]]--;
l++;
}
maxi_len = max(maxi_len,r-l+1);
r++;
}
return maxi_len;
}
};