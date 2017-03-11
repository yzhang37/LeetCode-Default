class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *slowptr = head, *fastptr = head;
        while (fastptr->next != NULL && fastptr->next->next != NULL)
        {
            fastptr = fastptr -> next -> next;
            slowptr = slowptr -> next;
            if (fastptr == slowptr)
                return true;
        }
        return false;
    }
};