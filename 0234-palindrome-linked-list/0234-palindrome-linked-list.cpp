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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev=nullptr,*cur=head;
        while(cur)
        {
            ListNode *next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) return true;
        ListNode *firstHalfEnd=findMiddle(head);
        ListNode *secondHalfStart=reverse(firstHalfEnd->next);
        ListNode *p1=head,*p2=secondHalfStart;
        bool res=true;
        while(res and p2)
        {
            if(p1->val!=p2->val) res=false;
            p1=p1->next;
            p2=p2->next;
        }
        firstHalfEnd->next=reverse(secondHalfStart);
        return res;
    }
};