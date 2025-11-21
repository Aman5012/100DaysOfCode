3234. Count the Number of Substrings With Dominant Ones
//QUESTION LINK: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/?envType=daily-question&envId=2025-11-15

TOPIC: String
Enumeration


CODE:
/////////////////////////   brutte force (TLE)   /////////////////////////////
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        int DomOne=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string temp =s.substr(i, j-i+1);
                int countZ= count(temp.begin(), temp.end(), '0');
                int countO = count(temp.begin(), temp.end(), '1');

                if(countO >= countZ * countZ) DomOne++;
                
            }
        }
        return DomOne;
    }
};


////////////////////////////////////    optimal solution  //////////////////////////////
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0';
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};
