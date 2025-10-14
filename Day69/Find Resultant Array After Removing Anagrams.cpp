2273. Find Resultant Array After Removing Anagrams
//QUESTION LINK: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13

// TOPIC: Array
// Hash Table
// String
// Sorting


CODE:


/////////////////// optimal appraoch (Two pointer approach) ///////////////////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n =words.size();
        int l=0;
        int r=l+1;
        ans.push_back(words[l]);
        while(l<r && r<n && l<n){
            string s1 = words[l];
            string s2 = words[r];
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if(s1==s2){
                l++;
                r++;
            }else {
                ans.push_back(words[r]);
                r++;
                l++;
            }
        }
        return ans;
    }
};


/////////////////////////////  brute force  //////////////////////
// Time Complexity: O(n²)
// Space Complexity: O(n)

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n =words.size();

        for(int i=0; i<n; i++){
                string s= words[i];
                sort(s.begin(), s.end());
            for(int j=i+1; j<n; j++){
                string s1= words[j];
                sort(s1.begin(), s1.end());
                if(s==s1){
                    words[j] = "0";
                } 
                if(s!=s1) {
                    i=j-1;
                    break;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(words[i]!="0")  ans.push_back(words[i]);
        }
        return ans;
    }
};
