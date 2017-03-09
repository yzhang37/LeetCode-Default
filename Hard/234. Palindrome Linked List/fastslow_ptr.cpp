/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode *fastptr = head, *slowptr = head;
        while (fastptr -> next != NULL && fastptr ->next->next != NULL)
        {
            slowptr = slowptr -> next;
            fastptr = fastptr -> next -> next;
        }
        ListNode *new_head = ReverseList(slowptr->next);
        
        bool flag = true;
        
        while (head != NULL && new_head != NULL)
        {
            if (head -> val != new_head -> val)
            {
                flag = false;
                break;
            }
            head = head -> next;
            new_head = new_head -> next;
        }
        
        return flag;
    }
    
    ListNode *ReverseList(ListNode *head)
    {
        ListNode *prev = NULL, *next = NULL;
        while (head != NULL)
        {
            //ȡ��ԭ���� head �ڵ����һ���ڵ�
            next = head->next;
            //����һ���ڵ㣬�ӵ� head �� next���൱�ڷ�ת
            head->next = prev;
            //��ǰ�� head ��Ϊ prev
            prev = head;
            //prev (�ɵ� head) �ȴ� next ��Ϊ�µ� head���������Լ���
            head = next;
        }
        return prev;
    }
};