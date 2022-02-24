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
     ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=NULL;
        while(head!=NULL and head->next!=NULL)
        {
            slow=(slow==NULL)?head:slow->next;
            head=head->next->next;
        }
        ListNode *mid=slow->next;
        slow->next=NULL;
        return mid;
    }
    ListNode* merge(ListNode* node1,ListNode* node2)
    {
        ListNode* temp=new ListNode();
        ListNode* t=temp;
        while(node1 and node2)
        {
            if(node1->val>node2->val)
            {
                t->next=node2;
                node2=node2->next;
            }
            else
            {
                t->next=node1;
                node1=node1->next;
            }
            t=t->next;
        }
        if(node1!=NULL)
        {
            t->next=node1;
        }
       else
        {
            t->next=node2;
        }
        temp=temp->next;
        return temp;
    }
    ListNode* mergeSort(ListNode* head)
    {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* mid=findMiddle(head);
        ListNode* left=mergeSort(head);
        ListNode* right=mergeSort(mid);
        return merge(left,right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
