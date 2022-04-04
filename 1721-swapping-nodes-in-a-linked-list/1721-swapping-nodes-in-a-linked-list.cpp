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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kth=NULL,*temp=head,*temp2=head;
        
        while(--k){
            temp2=temp2->next;
        }
        
        kth=temp2;
        temp2=temp2->next;
        while(temp2){
            temp2=temp2->next;
            temp=temp->next;
        }
        
        swap(kth->val,temp->val);
        return head;
    }
};