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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr or k<=1) return head;
        ListNode *cur=head,*prev=nullptr;
        while(true)
        {
            int count=0;
            ListNode *check=cur;
            while(check)
            {
                count++;
                if(count==k) break;
                check=check->next;
            }
            if(count<k) break;
            ListNode *lastNodeOfPrevPart=prev;
            ListNode *lastNodeOfSubList=cur;
            ListNode *next=nullptr;
            for(int i=0;cur!=nullptr and i<k;i++)
            {
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            if(lastNodeOfPrevPart!=nullptr) lastNodeOfPrevPart->next=prev;
            else head=prev;
            lastNodeOfSubList->next=cur;
            if(cur==nullptr) break;
            prev=lastNodeOfSubList;
        }
        return head;
    }
};