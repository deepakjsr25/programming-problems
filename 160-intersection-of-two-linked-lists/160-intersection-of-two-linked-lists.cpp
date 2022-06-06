/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *t1=headA;
        ListNode *t2=headB;
        
        while(t1->next){
            l1++;
            t1=t1->next;
        }
        
        while(t2->next){
            l2++;
            t2=t2->next;
        }
        
        if(t1->val!=t2->val){
            return NULL;
        }
        
        int move1=max(0,l1-l2);
        int move2=max(0,l2-l1);
        
        while(move1){
            headA=headA->next;
            move1--;
        }
        
        while(move2){
            headB=headB->next;
            move2--;
        }
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
    }
};