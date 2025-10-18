1081. Smallest Subsequence of Distinct Characters
//QUESTION LINK: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

TOPIC:String
Stack
Greedy
Monotonic Stack


CODE:
// TC: O(n)
// SC: O(1)


class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mpp;
        unordered_set<char> seen;

        for(char c:s){
            mpp[c]++;
        }

        string res ="";

        for(char c: s){
            mpp[c]--;
            if(seen.count(c)) continue;

            while(!res.empty() && res.back()> c && mpp[res.back()]>0){
                seen.erase(res.back());
                res.pop_back();
            }
            res.push_back(c);
            seen.insert(c);
        }
        return res;
    }
};
