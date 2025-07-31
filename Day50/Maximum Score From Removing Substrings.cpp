1717. Maximum Score From Removing Substrings
//QUESTION LNK: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2025-07-23

// TOPIC: String
// Stack
// Greedy

CODE:

// TC: O(n)
// sc: O(n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        int maxi = 0;
        string temp = "";

        // First pass: remove the more valuable substring
        if (x > y) {
            while (i < n) {
                if (!st.empty() && st.top() == 'a' && s[i] == 'b') {
                    st.pop();
                    maxi += x;
                } else {
                    st.push(s[i]);
                }
                i++;
            }
        } else {
            while (i < n) {
                if (!st.empty() && st.top() == 'b' && s[i] == 'a') {
                    st.pop();
                    maxi += y;
                } else {
                    st.push(s[i]);
                }
                i++;
            }
        }

        // Now collect the remaining characters
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        // Second pass: remove the less valuable substring from remaining
        i = 0;
        n = temp.size();
        while (i < n) {
            if (x > y) {
                if (!st.empty() && st.top() == 'b' && temp[i] == 'a') {
                    st.pop();
                    maxi += y;
                } else {
                    st.push(temp[i]);
                }
            } else {
                if (!st.empty() && st.top() == 'a' && temp[i] == 'b') {
                    st.pop();
                    maxi += x;
                } else {
                    st.push(temp[i]);
                }
            }
            i++;
        }

        return maxi;
    }
};
