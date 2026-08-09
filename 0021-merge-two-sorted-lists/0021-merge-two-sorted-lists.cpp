class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* head;
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        if (head1->val <= head2->val) {
            head = head1;
            head1 = head1->next;
        } else {
            head = head2;
            head2 = head2->next;
        }

        ListNode* temp = head;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }

            temp = temp->next;
        }

        if (head1 != nullptr) {
            temp->next = head1;
        }

        if (head2 != nullptr) {
            temp->next = head2;
        }

        return head;
    }
};