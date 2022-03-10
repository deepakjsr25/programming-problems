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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        ListNode* temp=l1;
        l1=l1->next;
        ListNode* temp2=l2;
        l2=l2->next;
        temp->next=NULL;
        temp2->next=NULL;
        
        while(l1){
            ListNode* newnode=l1;
            l1=l1->next;
            newnode->next=temp;
            temp=newnode;
        }
        
        while(l2){
            ListNode* newnode=l2;
            l2=l2->next;
            newnode->next=temp2;
            temp2=newnode;
        }
        
        int carry=0;
        ListNode* head;
        ListNode* head2;
        while(temp || temp2 || carry){
            int a=temp?temp->val:0;
            int b=temp2?temp2->val:0;
            int sum=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            
            ListNode* temp3=new ListNode(sum);
            if(!head){
                head=temp3;
                head2=head;
            }
            else{
                head->next=temp3;
                head=head->next;
            }
            
            temp=temp?temp->next:NULL;
            temp2=temp2?temp2->next:NULL;
        }
        
        ListNode* temp3=head2;
        head2=head2->next;
        temp3->next=NULL;
        while(head2){
            ListNode* newnode=head2;
            head2=head2->next;
            newnode->next=temp3;
            temp3=newnode;
        }
        
        return temp3;
    }
};