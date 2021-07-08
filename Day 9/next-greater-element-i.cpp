// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp; // for storing only the key = element ,value=next greater i.e only storing elements which have next greater elements
        vector<int>res; // for storing and returning the result
        stack<int>st; // for checking
        for(int i=0;i<nums2.size();i++) // traversing nums2
        {
            while(!st.empty()&&nums2[i]>st.top())  //For example [9, 8, 7, 3, 2, 1, 6] The stack will first contain [9, 8, 7, 3, 2, 1] and then we see 6 which is greater than 1 so we pop 1 2 3 whose next greater element should be 6
            {
                mp[st.top()]=nums2[i]; // put 6 as next greater for all the popped elements
                st.pop(); 
            }
            st.push(nums2[i]); // for starting case and if while doesnt satisfies
        }
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(mp.count(nums1[i])?mp[nums1[i]]:-1); // travesing the nums1 array and searching in map if its next greater is present or not.eg - for 1,2,3 6 is next greater so count will be > 0,for them.so we will push their next greater in res vector. FOR map KEY-> nums1[i], VALUE->NEXT GREATER ELEMENT OR -1.
        }
        return res;
    }
};
