class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
ListNode *head = new ListNode(-1);
ListNode *tmp = head;
int carry = 0;
while(l1 || l2 || carry){
int sum = 0;
if(l1!=NULL){
sum += l1->val;
l1 = l1->next;
}
if(l2!=NULL){
sum += l2->val;
l2 = l2->next;
}
sum+=carry;
carry = sum/10;
ListNode *temp = new ListNode(sum%10);
tmp->next = temp;
tmp = tmp->next;
}
return head->next;
}
};