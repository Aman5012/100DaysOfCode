5. Longest Palindromic Substring

//QUESTION LINK: https://leetcode.com/problems/longest-palindromic-substring/

TOPIC: Two Pointers
String
Dynamic Programming


CODE:
/////////////   optimal solution  //////////////////////

// TC: O(n.n);
// SC: O(n)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;

        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxi = 0, endIndex = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    // candidate substring in original string
                    int len = dp[i][j];
                    int startS = i - len;              // start index in s
                    int startRev = n - j;              // start index in s (mapped from reverse)

                    //  ensure substring is palindrome (start matches reverse position)
                    if (startS == startRev && len > maxi) {
                        maxi = len;
                        endIndex = i; // ending index in s
                    }
                }
            }
        }

        return s.substr(endIndex - maxi, maxi);
    }
};





//////////////////////brute force appraoch //////////
// TC: O(n^3)
// SC: O(n)

class Solution {
public:
    bool isPal(string temp){
        int t=temp.size();
        int l=0;
        int r=t-1;

        while(l<=r){
            if(temp[l]!=temp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n =s.size();
        if(n==1) return s;

        int maxi=0;
        string ans="";
        for(int l=0; l<n; l++){
            for(int r=0; r<n; r++){
                string temp=s.substr(l, r+1);
                if(isPal(temp)){
                    if(maxi<temp.size()){
                         ans = temp;
                        maxi = temp.size();
                    }
                }
            }
        }
        return ans;
        
    }
};
