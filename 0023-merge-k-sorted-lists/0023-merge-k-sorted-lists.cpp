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
    struct valComp
    {
        bool operator()(ListNode *x,ListNode *y)
        {
            return x->val>y->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,valComp> minHeap;
        for(auto root:lists)
        {
            if(root!=nullptr) minHeap.push(root);
        }
        ListNode *resHead=nullptr,*resTail=nullptr;
        while(!minHeap.empty())
        {
            auto node=minHeap.top();
            minHeap.pop();
            if(resHead==nullptr) resHead=resTail=node;
            else
            {
                resTail->next=node;
                resTail=resTail->next;
            }
            if(node->next!=nullptr) minHeap.push(node->next);
        }
        return resHead;
    }
};