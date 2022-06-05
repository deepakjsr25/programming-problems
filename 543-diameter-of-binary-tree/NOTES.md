if(root==NULL){
return 0;
}
int maxi=0;
lengthtree(root,maxi);
if(maxi==1){
return 0;
}
return (maxi-1);
}
int lengthtree(TreeNode* root,int &maxi){
if(root==NULL){
return 0;
}
int op=lengthtree(root->left,maxi);
int op2=lengthtree(root->right,maxi);
if(1+op+op2>maxi){
maxi=1+op+op2;
}
return 1+max(op,op2);
}
};