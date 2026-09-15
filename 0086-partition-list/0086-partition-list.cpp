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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sHead = new ListNode(0);
        ListNode* lHead = new ListNode(0);

        ListNode* sTail = sHead;
        ListNode* lTail = lHead;

        ListNode* curr = head;

        while(curr != NULL){
            if(curr -> val >= x){
                lTail -> next = curr;
                lTail = lTail -> next;
            } else {
                sTail -> next = curr;
                sTail = sTail -> next;
            }

            curr = curr -> next;
        }

        sTail -> next = lHead -> next;
        lTail -> next = NULL;

        return sHead -> next != NULL ? sHead -> next : lHead -> next;
    }
};