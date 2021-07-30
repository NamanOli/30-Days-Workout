// https://leetcode.com/problems/reorder-list/

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

/* 1->2->3->4->5
find mid
1->2 3->4->5
1->2 5->4->3
merge function
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)return;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode*l1=head;
        ListNode *l2=reverse(slow);
        merge(l1,l2);
    }
private:
    ListNode *reverse(ListNode*l2)
    {
        if(l2==NULL)return NULL;
        ListNode*prev=NULL;
        ListNode*curr=l2;
        ListNode*next=l2->next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
private:
    void merge(ListNode*l1,ListNode*l2)
    {
        while(l2!=NULL)
        {
            ListNode*next=l1->next;
            l1->next=l2;
            l1=l2;
            l2=next;
        }
    }
};
