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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return nullptr;
        if(n==1) return lists[0];
        priority_queue<pair<int,ListNode*>> pq;
        for(int i=0;i<n;i++)
        {
            if(lists[i])
                pq.push({-lists[i]->val,lists[i]});
        }
        if(pq.size()==0) return nullptr;
        ListNode *head=nullptr,*tail;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            if(head==nullptr)
            {
                ListNode *cur=new ListNode(-temp.first);
                head=cur;
                tail=cur;
            }
            else
            {
                ListNode *cur=new ListNode(-temp.first);
                tail->next=cur;
                tail=cur;
            }
            if(temp.second->next)
            {
                temp.second=temp.second->next;
                pq.push({-temp.second->val,temp.second});
            }
        }
        return head;
    }
};