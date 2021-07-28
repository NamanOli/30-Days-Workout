// https://leetcode.com/problems/add-two-numbers-ii/
// Time: O(m+n)
// Auxillary Space: O(m+n)

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
    private:
    ListNode*push_front(ListNode*head, int val){
        ListNode* t=new ListNode(val);
        t->next=head;
        return t;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode*head=NULL;
        int carry=0;
        while(!s1.empty() or !s2.empty()){
            int val=carry;
            if(!s1.empty()){
                val+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                val+=s2.top();
                s2.pop();
            }
            head=push_front(head,val%10);
            carry=val/10;
        }
        if(carry)
            head=push_front(head,1);
        return head;
    }
};

/*
One possible idea is to reverse both the linked lists and then, add elements one by one.

ListNode* rev(ListNode* c){
        ListNode*p=NULL,*r;
        while(c){
            r=c->next;
            c->next=p;
            p=c;
            c=r;
        }
        return p;
    }
    int count(ListNode*l1){
        int c=0;
        while(l1){
            c++;
            l1=l1->next;
        }
        return c;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1);
        l2=rev(l2);
        int c=0,p,q;
        ListNode*t;
        p=count(l1);
        q=count(l2);
        if(p>q)
            t=l1;
        else
            t=l2;
        while(l1&&l2){
            c=l1->val+l2->val+c;
            l1->val=c%10;
            l2->val=c%10;
            c/=10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            c=l1->val+c;
            l1->val=c%10;
            c/=10;
            l1=l1->next;
        }
        while(l2){
            c=l2->val+c;
            l2->val=c%10;
            c/=10;
            l2=l2->next;
        }
        t=rev(t);
        if(c){
            ListNode*l=new ListNode(1);
            l->next=t;
            t=l;
        }
        return t;
    }
Time: O(m+n)
Auxillary space: O(1).*/
