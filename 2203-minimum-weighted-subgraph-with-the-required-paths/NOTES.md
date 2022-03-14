vector<int> vis(n,0);
queue<int> q;
q.push(src1);
vector<int> dist(n,-1);
dist[src1]=0;
while(!q.empty()){
// cout<<"";
int from=q.front();
if(vis[from]){
q.pop();
continue;
}
vis[from]=1;
// cout<<from<<endl;
auto it=edge[q.front()];
q.pop();
int len=it.size();
for(int i=0;i<len;i++){
if(dist[it[i].first]==-1){
dist[it[i].first]=dist[from]+it[i].second;
}
else{
dist[it[i].first]=min(dist[it[i].first],dist[from]+it[i].second);
}
// cout<<it[i].first<<" "<<dist[it[i].first]<<endl;