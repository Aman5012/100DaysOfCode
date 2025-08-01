876. Middle of the Linked List
//QUESTION LNK: https://leetcode.com/problems/middle-of-the-linked-list/description/

TOPIC: Linked List
Two Pointers


CODE:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //////////////////  optimal (two pointer approach )  /////////////////
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow =head;
        ListNode* fast =head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

//////////////////////   brute force appraoch  ///////////////
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp =head;
        int count=0;
        while(temp != NULL){
            count++;
            temp = temp->next;

        }
        int move = count/2;
        while(move>0){
            head = head->next;
            move--;
        }
        return head;
    }
};
