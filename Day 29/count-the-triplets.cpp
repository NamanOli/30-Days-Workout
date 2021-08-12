// https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    sort(arr,arr+n);
    
    int j,k,c=0;
    for(int i=0;i<n-2;i++)
    {
        j=i+1;
        k=j+1;
        while(k<n)
        {
            if(arr[i]+arr[j]==arr[k])
            {
                c++;
                j++;
            }
            else if(arr[k]>arr[i]+arr[j])
            {
                j++;
                k--;
            }
            k++; 
        }
    }
    if(c==0)
    {
        return c;
    }
    else
    {
        return c;
    }
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

 
