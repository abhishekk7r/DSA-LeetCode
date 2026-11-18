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
    public ListNode middleNode(ListNode head) {
        int count = 0;
        var curr = head;
        while(curr != null) {
            count++;
            curr = curr.next;
        }

        int steps = (count/2);

        curr = head;
        while(steps > 0){
            steps--;
            curr = curr.next;
        }


        return curr;
    }
}