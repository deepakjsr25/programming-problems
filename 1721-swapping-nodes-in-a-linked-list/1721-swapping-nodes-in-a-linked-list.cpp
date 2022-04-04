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
    ListNode* swap=NULL;
    ListNode* swapNodes(ListNode* head, int k) {
        swapfunc(head,k,0);
        return head;
    }
    
    int swapfunc(ListNode* head,int k,int st){
        if(head==NULL){
            return 0;
        }
        
        st++;
        if(st==k){ //1
            swap=head;
        }
        
        int op=1+swapfunc(head->next,k,st);
        
        if(op==k){
            // cout<<swap->val<<" "<<op<<endl;
            int temp=swap->val;
            swap->val=head->val;
            head->val=temp;
        }
        
        return op;
    }
};