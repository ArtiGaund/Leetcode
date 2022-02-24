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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode* mid=getMid(head);
        ListNode *left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
    ListNode *getMid(ListNode *head)
    {
        ListNode* midprev=nullptr;
        while(head!=nullptr and head->next!=nullptr)
        {
            midprev=(midprev==nullptr?head:midprev->next);
            head=head->next->next;
        }
        ListNode *mid=midprev->next;
        midprev->next=nullptr;
        return mid;
    }
    ListNode* merge(ListNode *l1,ListNode* l2)
    {
        ListNode *dummy=new ListNode(0);
        ListNode *tail=dummy;
        while(l1 and l2)
        {
            if(l1->val<=l2->val)
            {
                tail->next=l1;
                l1=l1->next;
                tail=tail->next;
            }
            else
            {
                tail->next=l2;
                l2=l2->next;
                tail=tail->next;
            }
        }
        tail->next=(l1?l1:l2);
        return dummy->next;
    }
};