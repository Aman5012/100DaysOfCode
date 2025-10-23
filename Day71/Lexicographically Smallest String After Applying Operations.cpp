1625. Lexicographically Smallest String After Applying Operations
//QUESTION LINK: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/?envType=daily-question&envId=2025-10-19

TOPIC: String
Depth-First Search
Breadth-First Search
Enumeration


CODE
class Solution {
public:
    void rotate(string &s, int b) {
        int n = s.size();
        b %= n;
        s = s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallest = s;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            smallest = min(smallest, curr);

            // 1Add operation on odd indices
            string temp = curr;
            for (int i = 1; i < temp.size(); i += 2)
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';

            if (!vis.count(temp)) {
                vis.insert(temp);
                q.push(temp);
            }

            // Rotate operation
            rotate(curr, b);
            if (!vis.count(curr)) {
                vis.insert(curr);
                q.push(curr);
            }
        }

        return smallest;
    }
};
