Largest number in K swaps

//QUESTION LNK: https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

TOPIC: Strings, Backtracking, Data Structures, Algorithms


CODE:

//  TC: O(n^k)
//  SC: O(n+k)

class Solution {
  public:
    void solve(string& s, int k, int start, string& res ){
        if(k==0 || start== s.size()){
            return;
        }
        char maxi = *max_element(s.begin()+ start, s.end());
        for(int i=start+1; i<s.size(); i++){
            if(s[start]< s[i] && s[i]== maxi){
                swap(s[start], s[i]);
                if(s.compare(res)>0) res=s;
                solve(s, k-1, start+1, res);
                swap(s[start], s[i]);
            }
        }
        solve(s, k, start+1, res);
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        string res=s;
        int start=0;
        solve(s, k, start, res);
        return res;
    }
};
