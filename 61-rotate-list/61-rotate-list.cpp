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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head){
            return head;
        }
        
        ListNode* last=head;
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        
        head=last;
        k=k%cnt;
        
        if(k==0){
            return head;
        }
        
        k=cnt-k;
        ListNode* last2;
        while(k){
            last2=head;
            head=head->next;
            k--;
        }
        
        ListNode* start=head;
        while(head->next){
            head=head->next;
        }
        
        head->next=last;
        last2->next=NULL;
        
        
        return start;        
    }
};