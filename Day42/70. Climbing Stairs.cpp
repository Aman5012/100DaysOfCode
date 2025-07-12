70. Climbing Stairs
//QUESTION LNK:  https://leetcode.com/problems/climbing-stairs/description/

TOPIC: DP, recurdion


CODE:

// /////////////////////////   recursive solution  /////////////
TC: O(2^n);
SC: O(n)
class Solution {
public:

    int solve(int n){
        if(n<0) return 0;
        if(n==0) return 1; // one way to saty at ground

        int one_step = solve(n-1);
        int two_step = solve(n-2);
        return one_step + two_step;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};

/////////////////////////   memoizes ///////////
// TC: O(n)
// SC: O(n)

class Solution {
public:
        int t[46];
    int solve(int n){
        if(n<0) return 0;

        if(t[n]!=-1) return t[n];
        if(n==0) return 1; // one way to saty at ground
        int one_step = solve(n-1);
        int two_step = solve(n-2);
        return t[n]= one_step + two_step;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};

////////////////////////////  bottom up approach  ///////////

// TC: O(n)
// SC: O(n)

class Solution {
public:

    int climbStairs(int n) {
        if(n==1 || n==2 || n==3) return n;
        vector<int> arr(n+1);
        arr[0]=0;
        arr[1]=1;
        arr[2]=2;

        for(int i=3; i<n+1; i++){
            arr[i]= arr[i-1] + arr[i-2];
        }

        return arr[n];
    }
};
