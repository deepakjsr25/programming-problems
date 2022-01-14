class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> m;
        
        for(auto itr:wordList){
            m[itr]=2;
        }
        
        if(m[endWord]==0){
            return 0;
        }
        
        // int n=wordList.size();
        // int mini=endWord.length()-1;
        
        // if(mini+1>n){
        //     return 0;    
        // }
        
        queue<string> q;
        q.push(beginWord);
        int cnt=1;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string t=q.front();
                q.pop();
                int len=t.length();
                
                for(int i=0;i<len;i++){
                    char ch=t[i];
                    for(int j=97;j<=122;j++){
                        t[i]=(char)j;
                        
                        if(t==endWord){
                            cnt++;
                            return cnt;
                        }
                        
                        if(m[t]==2){
                            q.push(t);
                            m[t]=1;
                        }
                    }
                    t[i]=ch;
                }
            }
            cnt++;
        }
        
        return 0;
    }
};