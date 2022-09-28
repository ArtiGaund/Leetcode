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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode *first=head,*sec=head;
        for(int i=0;i<n;i++)
        {
            if(sec->next==nullptr)
            {
                if(i==n-1) head=head->next;
                return head;
            }
            sec=sec->next;
        }
        while(sec->next!=nullptr)
        {
            first=first->next;
            sec=sec->next;
        }
        first->next=first->next->next;
        return head;
    }
};