if(j==s.length()){
return 0;
}
if(s[j]==ss[i]){
i++;
}
j++;
return (j==s.length())?(i==len?1:0):search(temp->ch[s[j]-'a'],ss,i,len,s,j);
}
int numMatchingSubseq(string s, vector<string>& words) {
create(s);
int n=words.size();
int cnt=0;
for(int i=0;i<n;i++){
int len=words[i].size();
trie* temp=head;
int ans=search(temp->ch[s[0]-'a'],words[i],0,len,s,0);
cnt+=ans;
}
return cnt;
}
};