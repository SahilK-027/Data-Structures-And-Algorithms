/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// APPROACH 1: TWO PTR
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        if(fast == slow){
            return true;
        }
        if(fast == NULL){
            return false;
        }
        while(fast != slow && fast->next != NULL)
        {
            if(fast->next->next)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};


// APPROACH 2: HASH MAP
class Solution {
    //HASH MAP APPROACH
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head==NULL){
            return false;
        }
        ListNode *temp = head;
        unordered_map<ListNode * , int> map;
        while(temp->next != NULL){
            if(map.find(temp) == map.end()){
                //Node not found in map so add it to map
                map.emplace(temp , true);
            }
            else if(map[temp]==true){
                //Node found in map
                return true;
            }
            temp = temp->next;
        }
        return false;;
    }
};


// APPROACH 3: FLOYD's CYCLE DETECTION ALG
class Solution {
    //Floyd’s Cycle DETECTION Algorithm
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow != NULL && fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
