151. Reverse Words in a String
//QUESTION LINK: https://leetcode.com/problems/reverse-words-in-a-string/description/

TOPIC: Two Pointers
String


CODE:
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string reverseWords(string s) {
        int n =s.size();
        
        int r= n-1;
        string ans;
        
        while(r>=0 ){
            while(r>=0 && s[r]==' ') r--;

            if(r<0) break;
            int l =r;
            while(l>=0 && s[l] !=' ') l--;

            if(!ans.empty()) ans +=" ";
            ans +=s.substr(l+1, r-l) ;
            r=l;
        }

        return ans;
    }
};
