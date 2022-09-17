/*
Problem Statement

Design a data structure to implement 'N' stacks using a single array of size 'S'. It should support the following operations:
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
pop (M): Pops the top element from Mth Stack. Returns - 1 if the stack is empty, otherwise, returns the popped element.

*/

#include <bits/stdc++.h> 
class NStack
{
private:
    int *arr;
    int *top;
    int *nextFreeSpot;
    int availableFreeSpot;
    int n,s;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        this->n = N;
        this->s = S;
        this->arr = new int[s];
        this->top = new int[n];
        // Using memset function to initialize top array with -1
        memset(top, -1, n*sizeof(top[0]));
        this->nextFreeSpot = new int[s];
        // Initializing nextFreeSpot arr
        for(int i = 0 ; i <s-1 ;i ++){
            this->nextFreeSpot[i] = i+1;
        }
        // Udating last index to -1
        this->nextFreeSpot[s-1] = -1;
        
        // Setting free spot 
        this->availableFreeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //Check for overflow
        if(availableFreeSpot == -1){
            return false;
        }
        //Step 1: Find index to insert
        int index = availableFreeSpot;
        
        //Step 2: Update free spot
        availableFreeSpot = nextFreeSpot[index];
        
        //Step 3: Insert element in array
        arr[index] = x;
        
        //Step 4: Update nextFreeSpot
        nextFreeSpot[index] = top[m-1];
        
        //Step 5: Update top
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1){
            return -1;
        }
        // For pop do the exact reverse of push
        int index = top[m-1];
        top[m-1] = nextFreeSpot[index];
        nextFreeSpot[index] = availableFreeSpot;
        availableFreeSpot = index;
        return arr[index];
    }
};
