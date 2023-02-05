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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *cur=head,*prev=nullptr;
        for(int i=0;cur!=nullptr and i<left-1;i++)
        {
            prev=cur;
            cur=cur->next;
        }
        ListNode *lastNodeOfFirstPart=prev;
        ListNode *lastNodeOfSubList=cur;
        ListNode *next=nullptr;
        for(int i=0;cur!=nullptr and i<right-left+1;i++)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        if(lastNodeOfFirstPart!=nullptr) lastNodeOfFirstPart->next=prev;
        else head=prev;
        lastNodeOfSubList->next=cur;
        return head;
    }
};