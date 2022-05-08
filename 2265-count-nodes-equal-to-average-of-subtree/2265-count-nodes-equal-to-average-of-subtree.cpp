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
    int averageOfSubtree(TreeNode* root) {
        unordered_map<TreeNode*,pair<int,int>> m;
        return average(m,root);       
    }
    
    int average(unordered_map<TreeNode*,pair<int,int>>& m,TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int cnt=0;
        cnt=average(m,root->left)+average(m,root->right);
        m[root].first=root->val+m[root->left].first+m[root->right].first;
        m[root].second=1+m[root->left].second+m[root->right].second;
        
        int q=m[root].first/m[root].second;
        
        if(q==root->val){
            return cnt+1;
        }
        
        return cnt;
    }
};