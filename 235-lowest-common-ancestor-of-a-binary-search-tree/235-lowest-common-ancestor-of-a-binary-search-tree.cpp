/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lCA(root , p->val , q->val);
    }
    
    TreeNode* lCA(TreeNode* root, int p, int q)
    {
         if(p < root->val && q < root->val)
             return lCA(root->left , p , q);
        
         if(p > root->val && q > root->val)
             return lCA(root->right , p , q);
        
        
         if(p <= root->val && q > root->val)
             return root;
        
         return root;                  
    }
};