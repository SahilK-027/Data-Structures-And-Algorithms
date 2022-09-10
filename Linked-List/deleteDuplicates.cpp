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
// i/p -> 1-1-2-2-2-3
// o/p -> 1-2-3
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head == NULL){
            return NULL;
        }
        ListNode * curr = head;
        while(curr->next != NULL){
            if(curr->next->val != curr->val){
                curr = curr->next;
            }
        else{
                curr->next = curr->next->next;
            }
        }
    return head;
    }
};
