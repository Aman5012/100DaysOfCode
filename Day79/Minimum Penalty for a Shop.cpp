2483. Minimum Penalty for a Shop
//QUESTION LINK: https://leetcode.com/problems/minimum-penalty-for-a-shop/?envType=daily-question&envId=2025-12-27

TOPIC: String
Prefix Sum



CODE: 
///////////////////////////     optimal solution   //////////////
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();

        int reshR=INT_MAX;
        int minPenalty=INT_MAX;

        
        vector<int> nPref(n);
        vector<int> yPref(n);

        yPref[0]=customers[0]=='Y' ? 1 :0;
        nPref[0]=customers[0]=='N' ? 1 :0;

        for(int i=1; i<n; i++){
           yPref[i]=yPref[i-1] + (customers[i]=='Y' ? 1 : 0);
           nPref[i]=nPref[i-1] + (customers[i]=='N' ? 1 : 0);
        }

        for(int hr=0; hr<=n; hr++){
            int curPen = 0;
            // current place penality
            if(customers[hr]=='Y'){
                curPen++;
            }
            // back side penality
            if(hr>0){
                curPen += nPref[hr-1];
            }
            // reght side
            if(hr<n){
                curPen += yPref[n-1] - yPref[hr];
            }

            if(curPen<minPenalty){
                minPenalty=curPen;
                reshR=hr;
            }
            else if(curPen==minPenalty){
                if(hr<reshR){
                    reshR;
                }
            }
        }

        return reshR;
    }
};




/////////////////////////////  brute force   /////////////////////
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();

        int reshR=INT_MAX;
        int minPenalty=INT_MAX;

        for(int hr=0;hr<=n;hr++){
            int curPenalty=0;
            // before hr shop was open so , N will give 1 penalty

            if(hr<n && customers[hr]=='Y') curPenalty+=1;

            int j=hr-1;
            while(j>=0){
                if(customers[j]=='N'){
                    curPenalty+=1;
                }
                j--;
            }
            // /after hr shop was Y will give 1 penalty

            int k=hr+1;
            while(k<n){
                if(customers[k]=='Y'){
                    curPenalty+=1;
                }
                k++;
            }

            if(curPenalty<minPenalty){
                minPenalty=curPenalty;
                reshR=hr;
            }
            else if(curPenalty==minPenalty){
                if(hr<reshR){
                    reshR=hr;
                }
            }
        }

        return reshR;
    }
};
