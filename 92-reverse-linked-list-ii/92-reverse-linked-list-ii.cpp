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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){
            return head;
        }
        
        if(left==right){
            return head;
        }
        
        ListNode* temp=head;
        ListNode* prev=NULL;
        int cnt1=left-1,cnt2=right-1; //0 , 1
        
        while(cnt1!=0){
            prev=temp;
            temp=temp->next;
            cnt1--;
            cnt2--;
        }
        
        while(cnt2!=0){
            temp=temp->next;
            cnt2--;
        }
        
        ListNode* after=temp->next;
        
        if(prev!=NULL){
            temp=prev->next;
        }
        else{
            temp=head;
        }
        
        ListNode* rev=after; //null
        cnt1=right-left;
        while(cnt1!=0){
            ListNode* newnode=new ListNode(temp->val);
            newnode->next=rev;
            rev=newnode;
            temp=temp->next;
            cnt1--;
        }
        
        ListNode* newnode=new ListNode(temp->val);
        newnode->next=rev;
        rev=newnode;
        
        if(prev!=NULL){
            prev->next=rev;
        }
        else{
            head=rev;
        }
        
        return head;
    }
    
//     ListNode* reverse(ListNode* temp, int right){
//         if(head==NULL){
//             return head;
//         }
        
//         if(temp->val==right){
//             return temp;
//         }
        
//         ListNode* newnode=new ListNode(left);
//         ListNode* rev=reverse(temp->next,right);
//         ListNode* temp=rev->next;
//         rev->next=newnode;
//         newnode->next=temp;
//     }
};