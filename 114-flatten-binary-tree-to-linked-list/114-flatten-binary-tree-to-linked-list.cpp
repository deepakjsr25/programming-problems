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
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        
        TreeNode* node=root->right;
        root->right=root->left;
        flatten(root->left);
        flatten(node);
        
        root->left=NULL;
        
        TreeNode* prev;
        while(root){
            prev=root;
            root=root->right;
        }
        
        prev->right=node;
    }
};