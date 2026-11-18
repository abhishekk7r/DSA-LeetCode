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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        
        for(int i=1; i<left; i++){
            prev = prev.next;
        }

        var segStart = prev.next;
        var curr = segStart;
        ListNode before = null;

        for(int i = left; i <= right; i++){
            var next = curr.next;
            curr.next = before;
            before = curr;
            curr = next;
        }

        prev.next = before;
        segStart.next = curr;


        return dummy.next;
    }
}