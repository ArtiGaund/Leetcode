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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr or k<=0) return head;
        ListNode *lastNode=head;
        int len=1;
        while(lastNode->next)
        {
            len++;
            lastNode=lastNode->next;
        }
        lastNode->next=head;
        k%=len;
        int skipLen=len-k;
        ListNode *lastNodeOfRotatedList=head;
        for(int i=0;i<skipLen-1;i++)
            lastNodeOfRotatedList=lastNodeOfRotatedList->next;
        head=lastNodeOfRotatedList->next;
        lastNodeOfRotatedList->next=nullptr;
        return head;
    }
};