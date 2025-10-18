Children Sum in a Binary Tree

//QUESTION LINK: https://www.geeksforgeeks.org/problems/children-sum-parent/1

TOPIC: Tree


CODE:
// TC:O(n)
// SC: O(H)

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    int solve(Node* root){
        if(!root || (!root->left && !root->right)) return 1;
        
        int leftVal = root->left ? root->left->data : 0;
        int rightVal = root->right ? root->right->data : 0;
        
        int okk  = (root->data == leftVal + rightVal);
        
        return okk && solve(root->left) && solve(root->right);
         
        
    }
    int isSumProperty(Node *root) {
        if(root==NULL) return 1;
        
        return solve(root);
    }
};
