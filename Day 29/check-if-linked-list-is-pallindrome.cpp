// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node*temp=head;
        stack<int>s;
        //Your code here
        while(temp)
        {
            s.push(temp->data);
            temp=temp->next;
        }
        while(!s.empty())
        {
            int t=s.top();
            if(t!=head->data)
            {
                return 0;
            }
            s.pop();
            head=head->next;
        }
        if(s.empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
