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
            //取出原来， head 节点的下一个节点
            next = head->next;
            //将上一个节点，接到 head 的 next，相当于翻转
            head->next = prev;
            //当前的 head 作为 prev
            prev = head;
            //prev (旧的 head) 等待 next 作为新的 head，来连接自己。
            head = next;
        }
        return prev;
    }
};