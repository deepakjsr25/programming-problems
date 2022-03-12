/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* temp=head;
        while(temp){
            Node* temp2=new Node(temp->val);
            temp2->next=temp->next;
            temp->next=temp2;
            temp=temp->next->next;
        }
        
        temp=head;
        Node* first=head;
        Node* second=head->next->next;
        Node* peudonode=head->next;
        Node* peudohead=peudonode;
        
        while(temp){
            temp->next->random=temp->random?temp->random->next:NULL;
            temp=temp->next->next;
        }
        
        while(second){
            first->next=second;
            peudonode->next=second->next;
            peudonode=peudonode->next;
            first=first->next;
            second=second->next->next;
        }
        
        first->next=NULL;
        return peudohead;
    }
};