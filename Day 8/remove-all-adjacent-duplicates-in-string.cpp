// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/

class Solution {
public:
    string removeDuplicates(string S) {
        for (int i = 0; i < S.length() - 1 && !S.empty(); ++i)
    {
        // delete if 2 consecutive chars are duplicate
        if (S[i] == S[i + 1])
        {
            S.erase(i, 2);
            // After deleting next char may be duplicate of previous char eg: abba : after deleting bb --> aa may become consecutive duplicate characters so move i back to 1 previous char index but since for loop ++i increments by 1 lets decrement by -2 here
            // if i is 0 we can't go less than -1.. if we set to -1 then outer for loop resets back to 0 which will be the last character to compare with next character
            i = (i) ? i - 2 : i - 1;
        }
    }
    return S;
    }
};
