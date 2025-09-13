/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = null, itr = null;
        while(l1 != null || l2 != null){
            int num1 = l1 != null ? l1.val : 0;
            int num2 = l2 != null ? l2.val : 0;

            int sum = (num1 + num2) + carry;
            int val = sum % 10;
            carry = (sum > 9) ? 1 : 0;

            if(head == null){
                head = new ListNode(val);
                itr = head;
            } else {
                itr.next = new ListNode(val);
                itr = itr.next;
            }

            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
           // System.out.println("Sum " + sum + " Val " + val + " carry " + carry);
        }

        if(carry != 0) itr.next = new ListNode(carry);
        return head;
    }
}