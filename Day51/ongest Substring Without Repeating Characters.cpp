3. Longest Substring Without Repeating Characters

//QUESTION LNK: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

TOPIC: Hash Table
String
Sliding Window


CODE:

Time Complexity: O(n)
Space Complexity: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        if(n==0) return 0;
        unordered_set<char> st;
        int maxlen=0;
        int l=0;
        for(int r=0; r<n; r++){
            if(l<r && st.find(s[r]) != st.end()){ // duplicate found
                while(l<r && st.find(s[r]) != st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            maxlen= max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
