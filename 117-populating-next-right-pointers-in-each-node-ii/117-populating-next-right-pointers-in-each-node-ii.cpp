/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> m;
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int l=q.size();//1
            Node* prev=new Node();//null
            while(l--){
                Node* temp=new Node();
                temp=q.front();
                q.pop();
                
                if(prev==NULL){
                    prev=temp;
                }
                else{
                    prev->next=temp;
                    prev=prev->next;
                }
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return root;
    }
};