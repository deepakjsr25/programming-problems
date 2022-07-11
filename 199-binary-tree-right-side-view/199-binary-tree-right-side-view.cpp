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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        vector<int> ht(101,-1);
        view(root,v,ht,0);
        return v;
    }
    
    bool view(TreeNode* root, vector<int>& v, vector<int>& ht, int i){
        if(!root){
            return 0;
        }
        
        // cout<<i<<endl;
        if(ht[i]==-1){
            ht[i]=i;
            v.push_back(root->val);
        }
        
        if(!view(root->right,v,ht,i+1)){
            return view(root->left,v,ht,i+1);
        }
        
        return 1;
    }
};