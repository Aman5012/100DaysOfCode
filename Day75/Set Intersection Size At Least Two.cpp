757. Set Intersection Size At Least Two
//QUESTION LINK: https://leetcode.com/problems/set-intersection-size-at-least-two/description/?envType=daily-question&envId=2025-11-20

TOPIC: Array
Greedy
Sorting


CODE:

// Time Complexity: O(n²)
// Space Complexity: O(n)

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            if(a[1]==b[1]){ // when both interval end are equal 
                return a[0]> b[0];  //then laeger value of start be put first
            }
            return a[1] < b[1]; // smaller end put first
        });
        vector<int> res;

        for(auto &it : intervals){
            int l= it[0], r=it[1];

            int cnt=0;

            for(int i=res.size()-1; i>=0 && res[i] >= l; i--){
                if(res[i] <= r) cnt++;
                if(cnt==2) break;
            }

            if(cnt==2) continue;
            if(cnt==1){
                res.push_back(r);
            }else{
                res.push_back(r-1);
                res.push_back(r);
            }
        }
        return res.size();
    }
};
