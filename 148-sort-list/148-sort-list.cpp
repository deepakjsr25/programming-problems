/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        if(head->next==NULL){
            return head;
        }
        
        ListNode* newnode = sortList(head->next);
        
        if(newnode->val >= head->val){
            head->next=newnode;
            return head;
        }
        
        ListNode* prev=newnode;
        ListNode* curr=newnode;
        while(curr && curr->val<head->val){
            prev=curr;
            curr=curr->next;
        }
        
        ListNode* temp=prev->next;
        prev->next=head;
        prev=prev->next;
        
        if(!temp){
            prev->next=NULL;
        }
        else{
            prev->next=temp;
        }
        
        return newnode;
    }
};