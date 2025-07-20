2410. Maximum Matching of Players With Trainers
//QUESTION LNK: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13

TOPIC: Array
Two Pointers
Greedy
Sorting


CODE:

Time Complexity: O(n log n)
Space Complexity: O(1)
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size();
        int n = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans=0;
        int p=0;
        int t=0;
        while(p<m && t<n){
            if(players[p]<= trainers[t]){
                ans++;
                p++;
                t++;
            }
            else if(players[p]> trainers[t]) {
                t++;
            }
            else{
                p++;
            }
        }
        return ans;
    }
};
