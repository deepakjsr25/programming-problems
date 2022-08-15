if(beginWord==endWord ){
ans.push_back(st);
return;
}
if(beginWord==endWord){
return;
}
int n=beginWord.length();
for(int i=0;i<n;i++){
char c=beginWord[i];
for(int j=0;j<26;j++){
beginWord[i]=65+i;
if(m[beginWord]){
m[beginWord]=0;
ladders(beginWord,endWord,m,ans,st,cnt,curr_cnt);
m[beginWord]=1;
}
}
beginWord[i]=c;
}
return;
}
};