21. Merge Two Sorted Lists

//QUESTION LNK: https://leetcode.com/problems/merge-two-sorted-lists/

TOPIC: Linked List
Recursion


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
/////////////////////////////////////    approach 1  ////////////////////////
//  TC: O(m+n)
//  SC: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans;
        ListNode* temp = &ans;
        while(list1!= NULL && list2!=NULL){
            if(list1->val <= list2->val){
                temp -> next= list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2= list2->next;
            }
            temp = temp->next;
        }
                // Attach the remaining nodes (if any)
        if (list1 != NULL) temp->next = list1;
        if (list2 != NULL) temp->next = list2;
        return ans.next;
    }
};

////////////////////////////  inplace merge  ///////////////////////
// TC:O(m+n)
// SC: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // Make sure list1 starts with the smaller head
        if (list1->val > list2->val) swap(list1, list2);
        
        ListNode* ans = list1;

        while (list1 != NULL && list2 != NULL) {
            ListNode* temp = NULL;

            // Traverse list1 while values are smaller or equal
            while (list1 != NULL && list1->val <= list2->val) {
                temp = list1;
                list1 = list1->next;
            }

            // Link the last node of list1 to list2
            temp->next = list2;

            // Swap to make list1 always point to the smaller starting node
            swap(list1, list2);
        }

        return ans;
    }
};
