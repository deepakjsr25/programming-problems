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

// [2,4,3]
// [5,6,4]

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans;
        ListNode* ans2;
        while(l1 || l2 || carry){
            cout<<carry<<endl;
            int a=l1?l1->val:0;
            int b=l2?l2->val:0;
            int sum=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            cout<<sum<<" "<<carry<<endl;
            ListNode* temp=new ListNode(sum);
            if(!ans){
                ans=temp;
                ans2=ans;
            }
            else{
                ans->next=temp;
                ans=ans->next;
            }
            
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        
        return ans2;
    }
};