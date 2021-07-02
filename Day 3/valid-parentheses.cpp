// https://leetcode.com/problems/valid-parentheses/

// 1
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.length()<2)
        {
            return false;
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            if(st.empty()||((s[i]==')'&&st.top()!='(')||(s[i]=='}'&&st.top()!='{')||(s[i]==']'&&st.top()!='[')))
            {
                return false;
            }
            else if((s[i]==')'&&st.top()=='(')||(s[i]=='}'&&st.top()=='{')||(s[i]==']'&&st.top()=='['))
            {
                st.pop();
            }
            
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 2
class Solution {
public:
    bool isValid(string s) {
    stack<char> stk;
    for(const auto& c : s){
        switch(c){
            case '{':  stk.push('}'); break;
            case '[':  stk.push(']'); break;
            case '(':  stk.push(')'); break;
            default:
                if(stk.size() == 0 || c != stk.top()) return false;
                else stk.pop();
        }
    }
    return stk.size() == 0;
}
};
