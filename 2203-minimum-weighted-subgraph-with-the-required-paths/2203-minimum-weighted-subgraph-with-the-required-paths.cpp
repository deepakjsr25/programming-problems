class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long,long long>>> edge(n);
        for(auto it:edges){
            edge[it[0]].push_back(make_pair(it[1],it[2]));
        }
        
        vector<long long> vis(n,0);        
        queue<long long> q;
        q.push(src1);
        vector<long long> dist(n,-1);
        dist[src1]=0;
        
        while(!q.empty()){
            long long from=q.front();
            if(vis[from]){
               q.pop();
                continue;
            }
            vis[from]=1;
            auto it=edge[q.front()];
            q.pop();
            long long len=it.size();
            for(long long i=0;i<len;i++){
                if(dist[it[i].first]==-1){
                    dist[it[i].first]=dist[from]+it[i].second;
                }
                else{
                    dist[it[i].first]=min(dist[it[i].first],dist[from]+it[i].second);
                }
                q.push(it[i].first);
            }
        }
        
        
        vector<long long> vis2(n,0);        
        queue<long long> q2;
        q2.push(src2);
        vector<long long> dist2(n,-1);
        dist2[src2]=0;
        
        while(!q2.empty()){
            long long from=q2.front();
            if(vis2[from]){
               q2.pop();
                continue;
            }
            vis2[from]=1;
            auto it=edge[q2.front()];
            q2.pop();
            long long len=it.size();
            for(long long i=0;i<len;i++){
                if(dist2[it[i].first]==-1){
                    dist2[it[i].first]=dist2[from]+it[i].second;
                }
                else{
                    dist2[it[i].first]=min(dist2[it[i].first],dist2[from]+it[i].second);
                }
                q2.push(it[i].first);
            }
        }
        
        vector<vector<pair<long long,long long>>> edge2(n);
        for(auto it:edges){
            edge2[it[1]].push_back(make_pair(it[0],it[2]));
        }
        
        
        vector<long long> vis3(n,0);        
        queue<long long> q3;
        q3.push(dest);
        vector<long long> dist3(n,-1);
        dist3[dest]=0;
        
        while(!q3.empty()){
            long long from=q3.front();
            if(vis3[from]){
               q3.pop();
                continue;
            }
            vis3[from]=1;
            auto it=edge2[q3.front()];
            q3.pop();
            long long len=it.size();
            for(long long i=0;i<len;i++){
                if(dist3[it[i].first]==-1){
                    dist3[it[i].first]=dist3[from]+it[i].second;
                }
                else{
                    dist3[it[i].first]=min(dist3[it[i].first],dist3[from]+it[i].second);
                }
                q3.push(it[i].first);
            }
        }
        
        long long mini=10000000000;
        for(long long i=0;i<n;i++){
            if(dist[i]==-1 || dist2[i]==-1 || dist3[i]==-1){
                continue;
            }
                
            long long path_dist=dist[i]+dist2[i]+dist3[i];
            mini=min(path_dist,mini);
        }

        if(mini==10000000000){
            return -1;
        }
        
        return mini;
    }
};