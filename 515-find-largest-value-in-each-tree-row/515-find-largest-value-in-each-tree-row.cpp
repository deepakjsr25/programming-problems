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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        
        if(root==NULL){
            return v;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        v.push_back(root->val);
        
        while(!q.empty()){
            int len=q.size();
            int maxi=INT_MIN;
            while(len--){
                TreeNode* t=new TreeNode();
                t=q.front();
                q.pop();
                if(t->left!=NULL){
                    maxi=max(maxi,t->left->val);
                    q.push(t->left);
                }
                
                if(t->right!=NULL){
                    maxi=max(maxi,t->right->val);
                    q.push(t->right);
                }
            }
            
            v.push_back(maxi);
        }
        
        v.pop_back();
        return v;
    }
};