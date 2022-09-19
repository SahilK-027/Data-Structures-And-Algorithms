#include <bits/stdc++.h> 
class CircularQueue{
    private:
        int front;
        int rear;
        int *arr;
        int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        this->size = n;
        this->arr = new int[size];
        this->front = this->rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Full queue
        if((front == 0 && rear == this->size -1) || (rear == (front-1) % (size - 1))){
            //cout<<"Queue is full";
            return false;
        }
        
        // Empty queue
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        
        // Rear end if full
        else if(rear == this->size - 1 && front!= 0){
            rear = 0;
        }
        // Normal case
        else{
           rear++;
        }
           arr[rear] = value;
        return true;   
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Empty queue
        if(front == -1){
            return -1;
        }
        int ans = arr[front]; 
        arr[front] = -1;
        if(front == rear)
        {
            // Only 1 elelement in queue
            front = rear = -1;
        }
        else if(front == this->size-1){
            // Front at last element
            front = 0;
        }
        else{
            // Normal case
            front++;
        }
        return ans;
    }
};
