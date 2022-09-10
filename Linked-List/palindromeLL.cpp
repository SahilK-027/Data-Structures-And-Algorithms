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
//APPROACH 1: //Copy in array soln
              // TC-> O(N) 
              // SC-> O(N)
class Solution {
private:
    bool checkpal(vector<int> copy){
        int s = 0;
        int e = copy.size()-1;
        while(s<=e){
            if(copy[s]==copy[e])
            {
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        vector<int> copy;
        ListNode* temp = head;
        while(temp!=NULL){
            copy.push_back(temp->val);
            temp = temp->next;
        }
        return checkpal(copy);
    }
};


//APPROACH 2: // Reverse LL from middle onwards 
    // TC-> O(N) 
    // SC-> O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //Step 1: find mid
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast !=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow;
        
        //Strp 2: reverse LL from mid onwards
        ListNode* prev = NULL;
        ListNode* curr = mid->next;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        mid->next = prev;
        
        //Check from start to mid
        ListNode * temp =head;
        while(prev!=NULL){
            if(temp->val != prev->val){
                return false;
            }
            temp = temp->next;
            prev = prev->next;
        }
        return true;
    }
};
