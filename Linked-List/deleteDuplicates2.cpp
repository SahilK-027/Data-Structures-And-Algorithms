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
/*
We will Only solve one case for duplicate head, and recursion will remove all duplicates from the remaining list.

Base Case : Return head if head is NULL or there is only one node in the list.

Processing :
Step 1 - While head itself is duplicate delete head and update new head.
Step 2 - After updating head if head is NULL or there is only single node in list return head.

Recursive call : Now we have got a unique head, so we don't have to worry about it anymore.
Step 3 - We will ask recursion to delete duplicates from the next node and return its unique head. And when we'll get unique head from recursion, we'll attach it to our unique head.
Step 4 - We will return head once we have received an answer.*/

class Solution {
    /*Only solve one case of duplicate head and recursion will take care of remaining list*/
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base Case
        if(head == NULL || head->next ==NULL){
            return head;
        }
		
        // Step 1
        while(head != NULL && head->next != NULL && head->next->val == head->val){
             while(head->next != NULL && head->next->val == head->val){
                head = head->next;
            }
            head = head->next;
        }
		
        // Step 2
        if(head == NULL || head->next ==NULL){
            return head;
        }
        
        // Step 3
        head->next = deleteDuplicates(head ->next);
        
        // Step 4
        return head;
    }
};
