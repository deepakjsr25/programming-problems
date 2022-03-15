class Solution {
public:
string minRemoveToMakeValid(string s) {
int n = s.length();
string ans = "";
stack<int> st;
for(int i=0;i<n;i++){
if(s[i]=='('){
st.push(i);
}
else if(s[i]==')'){
if(st.empty())
s[i]='.';
else{
st.pop();
}
}
}
while(!st.empty()){
s[st.top()] = '.';
st.pop();
}
for(int i=0;i<n;i++){
if(s[i]=='.'){
continue;
}
ans+=s[i];
}
return ans;
}
};