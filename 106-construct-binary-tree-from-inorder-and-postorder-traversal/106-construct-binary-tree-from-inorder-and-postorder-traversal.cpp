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
    int indx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        
        indx=n-1;
        TreeNode* root;
        root=build(inorder,postorder,0,n-1,m);
        
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int start,int end,unordered_map<int,int> &m){
        if(start>end){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(postorder[indx]);
        indx--;

        // if(start==end){
        //     return root;
        // }
        
        int mid=m[root->val];
        
        root->right=build(inorder,postorder,mid+1,end,m);
        root->left=build(inorder,postorder,start,mid-1,m);
        
        return root;
    }
};