// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(head->val==1000000){
                return 1;
            }
            head->val=1000000;
            head=head->next;
        }
        
        return 0;
    }
};