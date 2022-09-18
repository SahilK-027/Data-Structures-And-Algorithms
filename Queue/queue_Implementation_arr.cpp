#include <bits/stdc++.h> 
class Queue {
private:
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        this->size = 100000000; // As max size of int array can be 10^8
        this->arr =  new int[size];
        this->qfront = 0;
        this->rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qfront == 0 && rear == size){
            //cout<<"Queue is full";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};
