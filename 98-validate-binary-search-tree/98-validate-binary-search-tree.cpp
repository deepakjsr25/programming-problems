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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        vector<int> v;
        check(root,v);
        
        int prev=v[0];
        
        for(int i=1;i<v.size();i++){
            if(v[i]<=prev){
                return 0;
            }
            
            prev=v[i];
        }
        
        return 1;
    }
    
    void check(TreeNode* root,vector<int>& v){
        if(root==NULL){
            return;
        }
        
        check(root->left,v);
        v.push_back(root->val);
        check(root->right,v);
    }
};