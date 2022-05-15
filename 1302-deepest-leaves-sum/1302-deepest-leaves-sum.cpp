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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        v.push_back(root->val);
        
        while(!q.empty()){
            int len=q.size();
            int sum=0;
            while(len--){
                TreeNode* t=new TreeNode();
                t=q.front();
                q.pop();
                if(t->left!=NULL){
                    sum+=t->left->val;
                    q.push(t->left);
                }
                
                if(t->right!=NULL){
                    sum+=t->right->val;
                    q.push(t->right);
                }
            }
            
            v.push_back(sum);
        }
        
        v.pop_back();
        return v.back();
    }
};