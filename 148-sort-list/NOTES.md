// step 3. merge l1 and l2
return merge(l1, l2);
}
ListNode merge(ListNode l1, ListNode l2) {
ListNode l = new ListNode(0), p = l;
while (l1 != null && l2 != null) {
if (l1.val < l2.val) {
p.next = l1;
l1 = l1.next;
} else {
p.next = l2;
l2 = l2.next;
}
p = p.next;
}
if (l1 != null)
p.next = l1;
if (l2 != null)
p.next = l2;
return l.next;
}
​
}