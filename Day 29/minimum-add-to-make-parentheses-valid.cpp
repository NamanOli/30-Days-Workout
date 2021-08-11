// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        if(!n) return 0;
        if(n==1) return n;
        int open=0;
        int ans=0;
        for(auto i:s){
            if(i=='(') open++;
            else{
                if(open>0) open--;
                else ans++;
            }
        }
        return ans+open;
    }
};
