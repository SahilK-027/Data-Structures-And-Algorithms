// Custom data type to push in min heap 
class Node{
    public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Comparator for min heap
class Comparator{
    public: 
    bool operator() (Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        // Step 1: Creating min heap
        priority_queue<Node*, vector<Node*>, Comparator> minHeap;
        
        // Step 2: Insert first element of all arrays in min heap
        for(int i = 0 ; i < k ; i++){
            // First element oif each array will be 0th element of ith row
            Node* temp = new Node(arr[i][0], i, 0);
            minHeap.push(temp);
        }
        
        // Step 3: Processing
        while(minHeap.size() > 0){
            // 1. Store the top of min heap
            Node* top = minHeap.top();
            
            // 2. Push top of min heap to answer array
            ans.push_back(top->data);
            minHeap.pop();
            
            // 3. Find the position of top element so that we can push its next element in minHeap
            int curr_row = top->row;
            int curr_col = top->col;
            // Checking for column of a particular current row is within index bound.
            if(curr_col + 1 < arr[curr_row].size()){
                Node* next = new Node(arr[curr_row][curr_col + 1], curr_row, curr_col + 1);
                minHeap.push(next);
            }
        }
        
        // Step 4: Return ans;
        return ans;
    }
};
