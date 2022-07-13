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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int ht=height(root);
        vector<vector<int>> v(ht);
        
        levelorder(root,0,v);
        return v;
    }
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1+max(height(root->left),height(root->right));
    }
    
    void levelorder(TreeNode* root,int height,vector<vector<int>> &v){
        if(root==NULL){
            return;
        }
        
        v[height].push_back(root->val);
        levelorder(root->left,height+1,v);
        levelorder(root->right,height+1,v);
    }
};