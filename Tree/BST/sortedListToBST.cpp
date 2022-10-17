class Solution {
private:
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // No list
        if(head == NULL){
            return NULL;
        }
        // Single node
        if(head->next == NULL){
            return (new TreeNode(head->val));
        }
        
        // find mid of list 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;
        
        while(fast != NULL && fast->next != NULL){
            mid = slow;
            slow = slow -> next;
            fast = fast->next ->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        mid->next = NULL;
        
        // Recursive call
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
