///approach 1 -- unordered map(TLE)
​
class Solution {
public:
int minDistance(string word1, string word2) {
unordered_map<string,int> m;
mini(m,word1,0);
int mini_tm=501;
mini2(m,word2,0,mini_tm);
return mini_tm;
}
void mini(unordered_map<string,int>& m,string word,int cnt){
int n=word.size();
if(m.find(word)==m.end()){
m.insert({word,cnt});
}
string s="";
for(int i=0;i<n;i++){
mini(m,s+word.substr(i+1,n),cnt+1);
s+=word[i];
}
}
void mini2(unordered_map<string,int>& m,string word,int cnt,int &mini_tm){
int n=word.size();
if(m.find(word)!=m.end()){
mini_tm=min(mini_tm,m[word]+cnt);
}
string s="";
for(int i=0;i<n;i++){
mini2(m,s+word.substr(i+1,n),cnt+1,mini_tm);
s+=word[i];
}
return;
}
};
​
​
/////approach 2 --- Dynamic prgramming