509. Fibonacci Number
//QUESTION LNK: https://leetcode.com/problems/fibonacci-number/description/

TOPIC: DP, recursion


CODE:

// // /////////////////////   recursive solution  //////////////
// TC: (2^n)
// SC: O(n)
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;

        return fib(n-1)+fib(n-2);
    }
};

// /////////////////////   recursive + memoised solution( top down)  //////////////
// TC: O(n)
// SC: O(n)
class Solution {
public:
        int dp[35];
    int solve(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];

        return dp[n]=solve(n-1)+solve(n-2);
    }
    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
}:

/////////////////////////  bottom up approach( tabulation)  //////////////4
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> arr(n+1);
        arr[0]=0;
        arr[1]=1;
        for(int i=2; i<n+1;i++){
            arr[i]= arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};
