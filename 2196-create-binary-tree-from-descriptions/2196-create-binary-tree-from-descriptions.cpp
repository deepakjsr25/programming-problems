/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Input: descriptions = [[39,70,1],[13,39,1],[85,74,1],[74,13,1],[38,82,1],[82,85,1]]
// Output: [38,82,null,85,null,74,null,13,null,39,null,70]

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        if(n==0){
            return NULL;
        }
        unordered_map<int, TreeNode*>mp;
        unordered_set<int> s;
        TreeNode* root=NULL;
        
        int parent, child, dir;
        
        for(int i=0; i<descriptions.size(); i++){
            parent=descriptions[i][0];
            child=descriptions[i][1];
            dir=descriptions[i][2];
            
            if(mp.find(parent)==mp.end()){
                TreeNode* parentNode=new TreeNode(parent);
                mp.insert({parent, parentNode});
            }
            
            if(mp.find(child)==mp.end()){
                TreeNode* childNode=new TreeNode(child);
                mp.insert({child, childNode});
            }
            if(dir==1){
                mp[parent]->left=mp[child];
            }else{
                mp[parent]->right=mp[child];
            }
            
            s.insert(child);
        }
        
        for(int i=0;i<n;i++){
            if(!s.count(descriptions[i][0])){
                return mp[descriptions[i][0]];
            }
        }
        
        
        return root;
    }
    
    // TreeNode* find()
};