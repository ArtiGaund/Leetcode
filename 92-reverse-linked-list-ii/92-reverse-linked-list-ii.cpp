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
    ListNode *reverseList(ListNode *head)
    {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode* cur=head,*next,*prev=nullptr;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int c=1;
        ListNode *revPrev=nullptr,*cur=head;
        while(c<left)
        {
            revPrev=cur;
            cur=cur->next;
            c++;
        }
        ListNode *revStart=cur;
        while(c<right)
        {
            cur=cur->next;
            c++;
        }
        ListNode *revEnd=cur,*revNext=cur->next;
        cur->next=nullptr;
        ListNode *revPart=reverseList(revStart);
        if(revPrev)
        {
            revPrev->next->next=revNext;
            revPrev->next=revPart;
        }
        else
        {
            if(revNext) head->next=revNext;
            head=revPart;
        }
        return head;
    }
};