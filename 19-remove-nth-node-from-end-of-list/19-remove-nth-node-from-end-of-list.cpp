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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(removenode(head,n)==n){
            head=head->next;
        }
        
        return head;
    }
    
    int removenode(ListNode* head, int n){
        if(head==NULL){
            return 0;
        }
        
        int op=removenode(head->next,n);//1
        
        if(op==n){
            ListNode* temp =  head->next->next;
            head->next=temp;
        }
        
        return op + 1;
    }
};