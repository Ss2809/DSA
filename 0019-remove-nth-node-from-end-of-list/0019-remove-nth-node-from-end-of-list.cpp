class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Maintain gap
        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete nth node from end
        slow->next = slow->next->next;

        return dummy->next;
    }
};