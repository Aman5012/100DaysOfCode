2048. Next Greater Numerically Balanced Number
//QUESTION LINK: https://leetcode.com/problems/next-greater-numerically-balanced-number/?envType=daily-question&envId=2025-10-24

TOPIC: Hash Table
Math
Backtracking
Counting
Enumeration


CODE:
////////////////////////    using map  /////////////////
class Solution {
public:
    int nextBeautifulNumber(int n) {
        int ans=1;
        bool got =true;
        for(int i=n+1; i<=1224444; i++){
            unordered_map<int, int> mpp;
           
            int temp=i;
            int digits=0;
            while(temp>0){
                int digit = temp%10;
                temp = temp/10;
                if(digit>0)mpp[digit]++;
                digits++;

            }
            int sumFreq =0;
            bool allGood = true;
            for (auto &entry : mpp) {
                int d = entry.first;
                int freq  = entry.second;
                sumFreq += freq;

                if (freq != d) {
                    allGood = false;
                    break;  // mismatch → stop checking
                }
            }
            if(allGood && sumFreq == digits) return i;        
            }
            return -1;
    }
};


//////////////////////   iterative method //////////////////////////

class Solution {
public:
    bool balance(int x){
        vector<int> count(10);

        while(x>0){
            count[x%10]++;
            x=x/10;
        }
        for(int d=0; d<10; d++){
            if(count[d]>0 && count[d]!=d){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<2222222; i++){
            if(balance(i)){
                return i;
            }
        }
        return -1;
    }
};
