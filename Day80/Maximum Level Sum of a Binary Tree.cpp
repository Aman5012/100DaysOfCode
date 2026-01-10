1161. Maximum Level Sum of a Binary Tree
//QUESTION LINK: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

TOPIC: Tree
Depth-First Search
Breadth-First Search
Binary Tree


CODE:
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

//////////////////////////////    approach 1  ////////////////
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int bfs(TreeNode* root){
        if(!root) return 0;
        int maxi = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int minLevel=0;
        while(!q.empty()){
            int levelSize=q.size();
            long long currLevelSum = 0;
            level++;
            for(int i=0; i<levelSize; i++){
                TreeNode* currNode = q.front();
                q.pop();

                currLevelSum += currNode->val;

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            if(maxi < currLevelSum){
                maxi =currLevelSum;
                minLevel = level;
            }
        }
        return minLevel;
    }
    int maxLevelSum(TreeNode* root) {
        return bfs(root);
    }
};

/////////////////////   int this we use stack to store the sum of each level and store in the vector 

// TC: O(n)
// SC: O(n)
class Solution {
public:
    
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int> levelSum;

        while(!q.empty()){
            int sum=0;
            int levelSize = q.size();

            for(int i=0; i<levelSize; i++){
                TreeNode* currNode= q.front();
                q.pop();

                sum += currNode->val;

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            levelSum.push_back(sum);
        }
        
        // max_element returns an iterator to the first max value found
        auto it = max_element(levelSum.begin(), levelSum.end());

        // conveting it to index value 
        int minLevel = it - levelSum.begin() +1;
        return minLevel;
    }

};
