/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        
        if(head->child==NULL){
            flatten(head->next);
            return head;
        }
        
        Node* newnode=head->next;
        head->next=flatten(head->child);
        head->child->prev=head;
        head->child=NULL;
        
        Node* temp=head->next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=newnode;
        if(newnode){
            newnode->prev=temp;
        }
        
        return head;
    }
};