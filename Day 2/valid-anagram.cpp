// https://leetcode.com/problems/valid-anagram/

// O(N)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        int count=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto i:mp)
        {
            if(i.second!=0)
            {
                return false;
            }
           
        }
        return true;
    }
};
