116. Populating Next Right Pointers in Each Node
//QUESTION LINK: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

TOPIC: Linked List
Tree
Depth-First Search
Breadth-First Search
Binary Tree


CODE:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


//////////////////////////////  recursive solution  ////////////////////////////////
// TC: O(n)
// SC: O(H)
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;

        if(root->left != NULL) root->left->next = root->right;

        if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;

    }
};


/////////////////////  level order traversal ///////////////////////
// TC: O(n)
// SC: O(n)

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL || root->left==NULL) return root;

        queue<Node*>q;
        Node *prev =NULL;
        q.push(root);
        q.push(NULL);

         while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr == nullptr) {
            // end of current level
            prev = nullptr;                // reset prev for next level
            if (!q.empty()) q.push(nullptr);
        } else {
            if (prev) prev->next = curr;
            prev = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return root;
}
};
