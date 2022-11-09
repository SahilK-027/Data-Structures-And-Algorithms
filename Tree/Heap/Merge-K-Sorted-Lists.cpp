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
 OPTIMIZED SOLUTION USING MinHeap
 */

 // Comparator for min heap
class Comparator{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Step 1: Creating min heap
        priority_queue<ListNode*, vector<ListNode*>, Comparator> minHeap;
        int k = lists.size();
        // Boundary condition
        if(k == 0){
            return NULL;
        }


        // Step 2: Insert first element of all lists in min heap
        for(int i = 0 ; i < k ; i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }


        ListNode* head = NULL;
        ListNode* tail = NULL;
        // Step 3: Processing
        while(!minHeap.empty()){
            // 1. Store the top of min heap
            ListNode* top = minHeap.top();
            minHeap.pop();

            // 2. Push top of min heap to answer lists head
            // First insertion
            if(head == NULL){
                head = top;
                tail = top;
            }
            // Insertion second onwards
            else{
                tail->next = top;
                tail = top;
            }
            // If next element exists then insert in minHeap
            if(top -> next != NULL){
                minHeap.push(top->next);
            }
        }
        return head;
    }
};
