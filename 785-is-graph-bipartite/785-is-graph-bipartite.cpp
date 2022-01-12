class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n<=2){
           return 1; 
        }
        
        vector<int> val(n,-1);
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(val[i]==-1){         
                q.push(i);
                val[i]=0;
                
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for(auto itr:graph[t]){
                        if(val[itr]==-1){
                        val[itr]=(!val[t]);
                        q.push(itr);
                    }
                    else if(val[itr]==val[t]){
                        return false;
                    }
                }
            }
        }        
    }
        
        
        // for(int i=0;i<n;i++){
        //     if(val[i]==-1){
        //         return false;
        //     }
        // }
        return true;
    }
};