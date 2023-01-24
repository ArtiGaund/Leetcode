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
    void reorderList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return;
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *secondHalfHead=reverse(slow);
        ListNode *firstHalfHead=head;
        while(firstHalfHead and secondHalfHead)
        {
            ListNode *temp=firstHalfHead->next;
            firstHalfHead->next=secondHalfHead;
            firstHalfHead=temp;
            temp=secondHalfHead->next;
            secondHalfHead->next=firstHalfHead;
            secondHalfHead=temp;
        }
        if(firstHalfHead!=nullptr) firstHalfHead->next=nullptr;
        return;
    }
};