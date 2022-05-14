class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back(make_pair(it[1],it[2]));
        }
        
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1);
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        dist[k]=0;
        queue<int> q;
        q.push(k);
        
        while(!q.empty()){
            int t=q.front();
            // cout<<t<<endl;
            q.pop();
            for(auto it:adj[t]){
                 parent[it.first]=t;
                 if((dist[t]+it.second)<dist[it.first]){
                     dist[it.first]=dist[t]+it.second;
                     q.push(it.first); 
                 }
            }
        }
        
        int max_dist=0;
        for(int i=1;i<=n;i++){
            if(i==k){
                continue;
            }
            
            if(dist[i]==INT_MAX){
                return -1;
            }
            else{
                max_dist=max(max_dist,dist[i]);
            }
        }
        
        return max_dist;
    }
};