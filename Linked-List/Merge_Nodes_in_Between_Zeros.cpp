// Approach:
// We will solve for nodes between the first two 0s and recursion will solve the remaining list.

// Base Case:
// If there is no node left OR if no next node is left in the list then return the current head.

// Processing:
// Step 1: We'll take the temp node pointing to the next node to head
// Step 2: We will create newNode and we will go on updating the value of newNode till temp's value does not become 0
// And once temp's value becomes zero we will call recursion

// Recursive call:
// First, we will need to check if temp->next != NULL (Meaning whether temp is the last node of the list or not)
// Now recursion will solve further list and we will attach our newNode to the answer of recursion.

// Finally, we will return the newNode.

class Solution {
    //RECURSIVE SOLUTION
public:
    ListNode* mergeNodes(ListNode* head) {
	    // For fast i/o operation
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
		
        // Base Case 
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        //PROCESSING
        ListNode* temp = head->next;
        ListNode * newNode = new ListNode(0);
        while(temp != NULL && temp->val != 0){
            newNode->val += temp->val;
            temp = temp->next;
        }
        
        //RECURSIVE CALL
        if(temp->next != NULL){
            newNode->next = mergeNodes(temp);
        }
        
        //RETURN ANSWER
        return newNode;
    }
};
