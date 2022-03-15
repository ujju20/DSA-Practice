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
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1 and lists[0]==NULL)
            return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>> > pq;
        int k=lists.size();
        for(int i=0;i<k;i++)
        {
            if(lists[i])
            pq.push({lists[i]->val,lists[i]});
        }
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            
            ListNode* n=new ListNode(p.first);
            temp->next=n;
            temp=temp->next;
            if(p.second->next)
            pq.push({p.second->next->val,p.second->next});
        }
        return ans->next;
    }
};
