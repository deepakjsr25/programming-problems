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
        
        int ht=maxdepth(root);
        // cout<<ht<<endl;
        int sum=0;
        preorder(root,0,ht,sum);
        
        return sum;
    }
    
    void preorder(TreeNode* root,int ht,int max_ht,int &sum){
        if(root==NULL){
            return;
        }
        
        preorder(root->left,ht+1,max_ht,sum);
        preorder(root->right,ht+1,max_ht,sum);
        
        // cout<<ht<<" "<<max_ht<<" "<<root->val<<endl;
        if(ht+1==max_ht){
            sum+=root->val;
        }
    }
    
    int maxdepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1+max(maxdepth(root->left),maxdepth(root->right));
    }
};