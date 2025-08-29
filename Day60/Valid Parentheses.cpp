20. Valid Parentheses
//QUESTION LINK: https://leetcode.com/problems/valid-parentheses/

TOPIC: String
Stack


CODE:
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c: s ){
            if(c == '(' || c== '{' || c== '['){
                st.push(c);
            }
            else {
                if(st.empty()) return false;
                char topp = st.top();
                if((c  == ')' && topp != '(') 
                    || (c  == '}' && topp != '{') 
                    || (c  == ']' && topp != '[')) {
                    return false;
                }
                
                st.pop();
            }
        }
        return st.empty();
    }
};
