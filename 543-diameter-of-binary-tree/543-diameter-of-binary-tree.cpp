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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int maxi=count(root->left)+count(root->right);
        // cout<<maxi<<endl;
        int a=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        
        return max(a,maxi);
    }
    
    int count(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return 1+max(count(root->left),count(root->right)); 
    }
};