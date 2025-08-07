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
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<Integer> q = new PriorityQueue<>();
        for(var i:lists){
            ListNode head = i;
            while(head != null){
                q.add(head.val);
                head = head.next;
            }
        }

        ListNode start = null;
        ListNode head = null;
        if(q.peek() != null){
            head = new ListNode(q.poll());
        } else {
            return null;
        }

        start = head;

        while(!q.isEmpty()){
            ListNode node = new ListNode(q.poll());
            head.next = node;
            head = head.next;
        }

        return start;
    }
}