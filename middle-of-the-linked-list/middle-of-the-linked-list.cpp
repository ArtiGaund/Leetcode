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
    ListNode* middleNode(ListNode* head) {
        ListNode *mid=nullptr;
        int n=1;
        midPoint(head,&n,&mid);
        return mid;
    }
    void midPoint(ListNode *head,int *n,ListNode **mid)
    {
        if(head==nullptr)
        {
            *n=(*n)/2;
            return;
        }
        *n=*n+1;
        midPoint(head->next,n,mid);
        *n=*n-1;
        if(*n==0)
            *mid=head;
    }
};